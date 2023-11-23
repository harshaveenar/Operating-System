#include <stdio.h>

#define MAX_REQUESTS 100

void calculateSeekTime(int requests[], int numRequests, int initialPosition) {
    int seekTime = 0;
    int currentHeadPosition = initialPosition;

    printf("Order of service:\n");
    for (int i = 0; i < numRequests; i++) {
        printf("%d ", requests[i]);

        // Calculate the absolute seek time for the current request
        seekTime += abs(requests[i] - currentHeadPosition);

        // Update the current head position
        currentHeadPosition = requests[i];
    }

    printf("\nTotal Seek Time: %d\n", seekTime);
}

int main() {
    int numRequests;

    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);

    if (numRequests > MAX_REQUESTS) {
        fprintf(stderr, "Error: Number of disk requests exceeds the maximum limit.\n");
        return 1;
    }

    int requests[MAX_REQUESTS];

    printf("Enter the disk requests (separated by spaces):\n");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    int initialPosition;
    printf("Enter the initial head position: ");
    scanf("%d", &initialPosition);

    calculateSeekTime(requests, numRequests, initialPosition);

    return 0;
}
