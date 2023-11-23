#include <stdio.h>

#define MAX_RECORDS 100

void readFileWithIndex(int file[], int indexBlock[], int numRecords) {
    printf("Reading records with index block:\n");
    for (int i = 0; i < numRecords; i++) {
        int blockIndex = indexBlock[i];
        if (blockIndex >= 0 && blockIndex < numRecords) {
            printf("Record %d (Block %d): %d\n", i + 1, blockIndex + 1, file[blockIndex]);
        } else {
            printf("Invalid index in the index block for Record %d\n", i + 1);
        }
    }
}

int main() {
    int numRecords;

    printf("Enter the number of records in the file: ");
    scanf("%d", &numRecords);

    if (numRecords > MAX_RECORDS) {
        fprintf(stderr, "Error: Number of records exceeds the maximum limit.\n");
        return 1;
    }

    int file[MAX_RECORDS];
    int indexBlock[MAX_RECORDS];

    printf("Enter the records of the file (separated by spaces):\n");
    for (int i = 0; i < numRecords; i++) {
        scanf("%d", &file[i]);
    }

    printf("Enter the index block entries (separated by spaces, -1 for invalid entries):\n");
    for (int i = 0; i < numRecords; i++) {
        scanf("%d", &indexBlock[i]);
    }

    readFileWithIndex(file, indexBlock, numRecords);

    return 0;
}

