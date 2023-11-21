#include <stdio.h>
#include <stdlib.h>

// Struct for Memory Block
typedef struct MemoryBlock {
    int size;
    int allocated;
} MemoryBlock;

// Function to implement First Fit algorithm
void firstFit(MemoryBlock blocks[], int numOfBlocks, int requestedSize) {
    int firstBlock = -1;
    int i;

    for (i = 0; i < numOfBlocks; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= requestedSize) {
            firstBlock = i;
            break;
        }
    }

    if (firstBlock != -1) {
        blocks[firstBlock].allocated = 1;
        printf("Memory allocated to block %d\n", firstBlock + 1);
    } else {
        printf("Memory allocation failed\n");
    }
}

int main() {
    int numOfBlocks, requestedSize;
    int i;

    // Get number of memory blocks from user
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numOfBlocks);

    // Create memory blocks array
    MemoryBlock *blocks = (MemoryBlock *)malloc(numOfBlocks * sizeof(MemoryBlock));

    // Initialize memory blocks with random sizes and allocated status
    for (i = 0; i < numOfBlocks; i++) {
        blocks[i].size = rand() % 100 + 1;
        blocks[i].allocated = 0;
        printf("Block %d\nSize: %d\nAllocated: %d\n\n", i + 1, blocks[i].size, blocks[i].allocated);
    }

    // Get requested memory size from user
    printf("Enter the requested memory size: ");
    scanf("%d", &requestedSize);

    // Call firstFit function to allocate memory
    firstFit(blocks, numOfBlocks, requestedSize);

    // Free allocated memory
    free(blocks);

    return 0;
}
