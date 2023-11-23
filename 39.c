#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void cscan(int arr[], int head, int size, int disk_size) {
    int distance = 0;
    int cur_track;
    int left[MAX], right[MAX];
    int left_count = 0, right_count = 0;
    int i, j;

    // Finding the position of the head
    for (i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_count++] = arr[i];
        if (arr[i] > head)
            right[right_count++] = arr[i];
    }

    // Sorting the requests
    for (i = 0; i < left_count - 1; i++) {
        for (j = 0; j < left_count - i - 1; j++) {
            if (left[j] < left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < right_count - 1; i++) {
        for (j = 0; j < right_count - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    // Scanning to the right
    for (i = 0; i < right_count; i++) {
        cur_track = right[i];
        printf("Move from %d to %d\n", head, cur_track);
        distance += abs(cur_track - head);
        head = cur_track;
    }

    // Scanning to the left
    printf("Move from %d to %d\n", head, disk_size - 1);
    distance += disk_size - 1 - head;
    head = disk_size - 1;

    for (i = 0; i < left_count; i++) {
        cur_track = left[i];
        printf("Move from %d to %d\n", head, cur_track);
        distance += abs(cur_track - head);
        head = cur_track;
    }

    printf("Total distance: %d\n", distance);
}

int main() {
    int size, head, disk_size;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    int arr[MAX];

    printf("Enter the queue elements:\n");
    int i;
    for (i = 0; i < size; i++) { // Note: 'i' should be declared before the loop
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the size of the disk: ");
    scanf("%d", &disk_size);

    cscan(arr, head, size, disk_size);

    return 0;
}

