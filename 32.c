#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

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
    int recentUsage[MAX_FRAMES];
    int pageFaults = 0;

    int i, j; 

    for (i = 0; i < frames; i++) {
        framesArray[i] = -1; 
        recentUsage[i] = 0; 
    }

    printf("Incoming \t");
    for (i = 0; i < frames; i++) {
        printf("Frame %d\t", i + 1);
    }
    printf("\n");

    for (i = 0; i < pages; i++) {
        int page;

        printf("Enter page for reference %d: ", i + 1);
        scanf("%d", &page);
        pageReferenceString[i] = page;

        printf("%d\t\t", page);

        int pageFound = 0;
        for (j = 0; j < frames; j++) {
            if (framesArray[j] == page) {
                pageFound = 1;
                recentUsage[j] = i + 1; 
            }
        }

        if (!pageFound) {
            int minIndex = 0;
            for (j = 1; j < frames; j++) {
                if (recentUsage[j] < recentUsage[minIndex]) {
                    minIndex = j;
                }
            }

            framesArray[minIndex] = page;
            recentUsage[minIndex] = i + 1; 
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

