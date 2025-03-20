#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 65535
#define MAX_NUMBERS 65535

typedef struct MemoryBlock {
    int size;
    struct MemoryBlock* prev;
    struct MemoryBlock* next;
} MemoryBlock;

MemoryBlock* create_block(int size) {
    MemoryBlock* block = (MemoryBlock*)malloc(sizeof(MemoryBlock));
    block->size = size;
    block->prev = NULL;
    block->next = NULL;
    return block;
}

MemoryBlock* append_block(MemoryBlock* head, int size) {
    MemoryBlock* new_block = create_block(size);
    if (head == NULL) return new_block;

    MemoryBlock* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_block;
    new_block->prev = current;
    return head;
}

MemoryBlock* create_circular_list(int* numbers, int count) {
    if (count == 0) return NULL;

    MemoryBlock* head = NULL;
    for (int i = 0; i < count; i++) {
        head = append_block(head, numbers[i]);
    }

    // Connect head and tail to form circular list
    MemoryBlock* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    head->prev = tail;
    tail->next = head;
    return head;
}

int read_initial_memory(int* buffer) {
    char input[MAX_LINE_LENGTH];
    fgets(input, sizeof(input), stdin);
    
    int count = 0;
    char* token = strtok(input, " \n");
    while (token != NULL) {
        buffer[count++] = atoi(token);
        token = strtok(NULL, " \n");
    }
    return count;
}

void remove_node(MemoryBlock* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

int main() {
    int numbers[MAX_NUMBERS];
    int count = read_initial_memory(numbers);
    
    MemoryBlock* head = create_circular_list(numbers, count);
    int merged_size = -1;  // -1 indicates unmerged state
    
    char input[MAX_LINE_LENGTH];
    while (fgets(input, sizeof(input), stdin) != NULL) {
        int alloc = atoi(strtok(input, " \n"));
        
        if (merged_size != -1) {
            // Process merged memory
            if (merged_size >= alloc) {
                merged_size -= alloc;
                printf("%d\n", merged_size);
            } else {
                printf("memory out\n");
            }
            continue;
        }

        // Try to allocate in original memory blocks
        if (head->size >= alloc) {
            head->size -= alloc;
            printf("%d\n", head->size);
            
            if (head->size == 0) {
                if (head->next != head) {
                    head = head->next;
                    remove_node(head->prev);
                } else {
                    free(head);
                    merged_size = 0;
                }
            }
        } else {
            MemoryBlock* left = head->prev;
            MemoryBlock* right = head->next;
            int total_size = head->size;
            int allocated = 0;
            
            while (left != head) {
                total_size += left->size;
                
                if (left->size >= alloc) {
                    left->size -= alloc;
                    printf("%d\n", left->size);
                    if (left->size == 0) remove_node(left);
                    allocated = 1;
                    break;
                }
                
                if (right->size >= alloc) {
                    right->size -= alloc;
                    printf("%d\n", right->size);
                    if (right->size == 0) remove_node(right);
                    allocated = 1;
                    break;
                }
                
                left = left->prev;
                right = right->next;
            }
            
            if (!allocated) {
                merged_size = total_size;
                if (merged_size >= alloc) {
                    merged_size -= alloc;
                    printf("%d\n", merged_size);
                } else {
                    printf("memory out\n");
                }
            }
        }
    }
    
    return 0;
}