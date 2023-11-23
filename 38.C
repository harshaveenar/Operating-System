#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REQUESTS 100
#define MAX_BLOCKS 1000

typedef struct {
    int blockID;
    int fileID;
} BlockRequest;

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void SCAN(BlockRequest requests[], int n) {
    int currentTrack = requests[0].blockID;
    int seekCount = 0;
    int processed[MAX_BLOCKS] = {0};

    for (int i = 0; i < n; i++) {
        int j = 0;
        int minDiff = MAX_BLOCKS;
        int blockToBeAccessed = -1;

        while (j < n) {
            if (requests[j].blockID >= currentTrack && processed[requests[j].blockID] == 0) {
                int diff = requests[j].blockID - currentTrack;

                if (diff < minDiff) {
                    minDiff = diff;
                    blockToBeAccessed = j;
                }
            }

            j++;
        }

        if (blockToBeAccessed != -1) {
            seekCount += minDiff;
            currentTrack = requests[blockToBeAccessed].blockID;
            processed[currentTrack] = 1;

            printf("Block %d in file %d accessed\n", requests[blockToBeAccessed].blockID, requests[blockToBeAccessed].fileID);
        } else {
            if (currentTrack < MAX_BLOCKS - 1) {
                currentTrack++;
            } else {
                currentTrack = 0;
            }
        }
    }

    printf("Total number of seek operations: %d\n", seekCount);
}

int main() {
    BlockRequest requests[MAX_REQUESTS];
    int n;

    printf("Enter the number of block requests: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the file ID and block ID: ");
        scanf("%d %d", &requests[i].fileID, &requests[i].blockID);
    }

    SCAN(requests, n);

    return 0;
}
