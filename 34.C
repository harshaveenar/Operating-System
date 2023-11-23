#include <stdio.h>

#define MAX_RECORDS 100

void readFileSequentially(int file[], int numRecords) {
    printf("Reading records sequentially:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Record %d: %d\n", i + 1, file[i]);
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

    printf("Enter the records of the file (separated by spaces):\n");
    for (int i = 0; i < numRecords; i++) {
        scanf("%d", &file[i]);
    }

    readFileSequentially(file, numRecords);

    return 0;
}

