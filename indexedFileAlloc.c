#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

// Structure to represent an index block
struct IndexBlock {
    int data_blocks[MAX_BLOCKS];
};

// Function to initialize an index block
void initializeIndexBlock(struct IndexBlock* indexBlock) {
    for (int i = 0; i < MAX_BLOCKS; ++i) {
        indexBlock->data_blocks[i] = -1; // Initialize with -1 (invalid block)
    }
}

// Function to allocate a data block for a file
int allocateDataBlock(struct IndexBlock* indexBlock, int blockNumber) {
    for (int i = 0; i < MAX_BLOCKS; ++i) {
        if (indexBlock->data_blocks[i] == -1) {
            indexBlock->data_blocks[i]=blockNumber;
            return 1; // Successfully allocated
        }
    }
    return 0; // No free space in the index block
}

// Function to read data from a file
void readData(struct IndexBlock* indexBlock, int fileBlockNumber) {
        int flag=0;
       for(int i=0;i<MAX_BLOCKS;i++) 
       {
         if (indexBlock->data_blocks[i] != -1 && fileBlockNumber==indexBlock->data_blocks[i]) 
           { printf("Reading data from block %d\n", indexBlock->data_blocks[i]);
            flag=1;
            
            }
         }
         
          if(flag==0)  printf("Block %d is not allocated.\n", fileBlockNumber);
     
    
}

int main() {
    struct IndexBlock indexBlock;
    initializeIndexBlock(&indexBlock);

    // Allocate data blocks for a file (example)
    allocateDataBlock(&indexBlock, 5);
    allocateDataBlock(&indexBlock, 8);
    allocateDataBlock(&indexBlock, 12);

    // Read data from specific file blocks (example)
    readData(&indexBlock, 5);
    readData(&indexBlock, 8);
    readData(&indexBlock, 10); // Not allocated
    
    return 0;
}
