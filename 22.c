#include <stdio.h>
#include <stdlib.h>
typedef struct MemoryBlock {
    int size;
    int allocated;
} MemoryBlock;
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
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numOfBlocks);
    MemoryBlock *blocks = (MemoryBlock *)malloc(numOfBlocks * sizeof(MemoryBlock));
    for (i = 0; i < numOfBlocks; i++) {
        blocks[i].size = rand() % 100 + 1;
        blocks[i].allocated = 0;
        printf("Block %d\nSize: %d\nAllocated: %d\n\n", i + 1, blocks[i].size, blocks[i].allocated);
    }
    printf("Enter the requested memory size: ");
    scanf("%d", &requestedSize);
    firstFit(blocks, numOfBlocks, requestedSize);
    free(blocks);

    return 0;
}
