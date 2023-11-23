#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int findOptimal(int pages[], int frames[], int start, int end) {
    int index = -1, farthest = start;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = start; j < end; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == end) {
            return i;
        }
    }
    return (index == -1) ? 0 : index;
}

int main() {
    int frames, pages;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    if (frames > MAX_FRAMES) {
        fprintf(stderr, "Error: Number of frames exceeds the maximum limit.\n");
        return 1;
    }

    printf("Enter the total number of pages: ");
    scanf("%d", &pages);

    if (pages > MAX_PAGES) {
        fprintf(stderr, "Error: Number of pages exceeds the maximum limit.\n");
        return 1;
    }

    int pageReferenceString[MAX_PAGES];
    int framesArray[MAX_FRAMES];
    int pageFaults = 0;

    int i, j; // Move declarations outside the loop for C89 compatibility

    for (i = 0; i < frames; i++) {
        framesArray[i] = -1; // Initialize frames as empty
    }

    printf("Enter the page reference string (separated by spaces):\n");
    for (i = 0; i < pages; i++) {
        scanf("%d", &pageReferenceString[i]);
    }

    printf("Incoming \t");
    for (i = 0; i < frames; i++) {
        printf("Frame %d\t", i + 1);
    }
    printf("\n");

    for (i = 0; i < pages; i++) {
        int page = pageReferenceString[i];

        printf("%d\t\t", page);

        int pageFound = 0;
        for (j = 0; j < frames; j++) {
            if (framesArray[j] == page) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int index = findOptimal(pageReferenceString, framesArray, i + 1, pages);
            framesArray[index] = page;
            pageFaults++;
        }

        for (j = 0; j < frames; j++) {
            if (framesArray[j] != -1) {
                printf("%d\t\t", framesArray[j]);
            } else {
                printf("-\t\t");
            }
        }

        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}

