#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    int fileID;
    int blockID;
    struct Block *next;
} Block;

Block *allocateBlock(int fileID, int blockID) {
    Block *newBlock = (Block *)malloc(sizeof(Block));
    newBlock->fileID = fileID;
    newBlock->blockID = blockID;
    newBlock->next = NULL;
    return newBlock;
}

void freeFile(Block *firstBlock) {
    Block *currentBlock = firstBlock;
    while (currentBlock != NULL) {
        Block *nextBlock = currentBlock->next;
        free(currentBlock);
        currentBlock = nextBlock;
    }
}

void writeToFile(Block *firstBlock, int blockID, int fileID) {
    Block *currentBlock = firstBlock;
    while (currentBlock != NULL) {
        if (currentBlock->blockID == blockID && currentBlock->fileID == fileID) {
            printf("Block %d in file %d updated\n", blockID, fileID);
            return;
        }
        currentBlock = currentBlock->next;
    }
    printf("Block %d in file %d allocated\n", blockID, fileID);
    currentBlock->next = allocateBlock(fileID, blockID);
}

int main() {
    int fileID, blockID;
    Block *firstBlock = allocateBlock(1, 1);
    printf("Enter the file ID and block ID: ");
    scanf("%d %d", &fileID, &blockID);
    writeToFile(firstBlock, blockID, fileID);
    printf("Enter the file ID and block ID: ");
    scanf("%d %d", &fileID, &blockID);
    writeToFile(firstBlock, blockID, fileID);
    printf("Enter the file ID and block ID: ");
    scanf("%d %d", &fileID, &blockID);
    writeToFile(firstBlock, blockID, fileID);
    printf("Enter the file ID and block ID: ");
    scanf("%d %d", &fileID, &blockID);
    writeToFile(firstBlock, blockID, fileID);
    freeFile(firstBlock);
    return 0;
}
