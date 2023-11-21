#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int id;
    int size;
    int allocated;
} Block;

void initializeBlocks(Block* memoryBlocks, int memoryBlockSize) {
    int i;
    for(i = 0; i < memoryBlockSize; i++) {
        memoryBlocks[i].id = i + 1;
        memoryBlocks[i].size = rand() % 100 + 1;
        memoryBlocks[i].allocated = 0;
    }
}

void printBlocks(Block* memoryBlocks, int memoryBlockSize) {
    int i;
    for(i = 0; i < memoryBlockSize; i++) {
        printf("Block %d\n", memoryBlocks[i].id);
        printf("Size: %d\n", memoryBlocks[i].size);
        printf("Allocated: %d\n\n", memoryBlocks[i].allocated);
    }
}

int allocateMemory(Block* memoryBlocks, int memoryBlockSize, int requestedSize) {
    int maxDifference = -1;
    int bestBlockIndex = -1;
    int i;

    for(i = 0; i < memoryBlockSize; i++) {
        if(memoryBlocks[i].allocated == 0) {
            int difference = memoryBlocks[i].size - requestedSize;
            if(difference >= 0 && difference > maxDifference) {
                maxDifference = difference;
                bestBlockIndex = i;
            }
        }
    }

    if(bestBlockIndex != -1) {
        memoryBlocks[bestBlockIndex].allocated = 1;
        return bestBlockIndex;
    } else {
        return -1;
    }
}

int main() {
    int memoryBlockSize, requestedSize;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &memoryBlockSize);

    Block memoryBlocks[memoryBlockSize];

    initializeBlocks(memoryBlocks, memoryBlockSize);
    printBlocks(memoryBlocks, memoryBlockSize);

    printf("Enter the requested memory size: ");
    scanf("%d", &requestedSize);

    int blockIndex = allocateMemory(memoryBlocks, memoryBlockSize, requestedSize);

    if(blockIndex != -1) {
        printf("Memory allocated to block %d\n", memoryBlocks[blockIndex].id);
    } else {
        printf("Memory allocation failed. No suitable block found.\n");
    }

    return 0;
}
