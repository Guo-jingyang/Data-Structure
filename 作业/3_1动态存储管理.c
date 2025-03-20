#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAX_LINE_LENGTH = 65535;
int MAX_NUMBERS = 65535;


struct mem
{
	int size;
	struct mem* left;
	struct mem* right;
};


struct mem* create_mem (struct mem* head, int size)
{
	struct mem* memory = (struct mem*)malloc(sizeof(struct mem));
	memory -> size = size;
	memory -> left = NULL;
	memory -> right = NULL;
	
	
	if (head == NULL)
	{
		return memory;
	}
	
	
	struct mem* pointer = head;
	while (pointer -> right != NULL)
	{
		pointer = pointer -> right;
	}
	memory -> left = pointer;
	pointer -> right = memory;
	return head;
}


int main()
{
	// 读取初始内存空白区 
	char input[MAX_LINE_LENGTH];
	int numbers[MAX_NUMBERS];
	fgets(input, sizeof(input), stdin);
	int num, count = 0;
	char* token = strtok(input, " \n");
	while (token != NULL)
	{
		num = atoi(token);
		numbers[count++] = num;
		token = strtok(NULL, " \n");
	}
	
	
	// 创建链表，但首尾尚未连接 
	struct mem* head = NULL;
	head = create_mem(head, numbers[0]);
	for (int i=1; i<count; i++)
	{
		create_mem(head, numbers[i]);
	}
	
	
	// 首尾相连 
	struct mem* lpointer, *rpointer;
	rpointer = head;
	while (rpointer -> right != NULL)
	{
		rpointer = rpointer -> right;
	}
	head -> left = rpointer;
	rpointer -> right = head;
	
	
	int mergedsize = -1; // 合并后的内存的大小，若为-1，则说明尚未合并 
	int alloc, size; // 未进行内存合并时，每次循环中记录剩余内存总量 
	while (fgets(input, sizeof(input), stdin) != NULL)
	{
		// 读取分配的内存大小 
		char* token = strtok(input, " \n");
		alloc = atoi(token);
		
		
		if (mergedsize == -1)
		{ // 未进行过内存合并则执行 
			if (head -> size >= alloc) // 头节点内存足够 
			{
				head -> size -= alloc;
				printf("%d\n", head -> size);
				
				
				if (head -> size == 0) // 头节点移除
				{
					if (head -> right != head) // 若链表不为空，头节点转移 
					{
						head -> right -> left = head -> left;
						head -> left -> right = head -> right;
						rpointer = head -> right;
						free(head);
						head = rpointer;
					}
					else // 移除链表，确保不再访问链表
					{
						free(head);
						mergedsize = 0;
					}
				}
			}
			
			
			else
			{
				lpointer = head -> left;
				rpointer = head -> right;
				size = head -> size; 
				
				 
				while (lpointer != head) // 到达头节点说明此时需要进行内存合并 
				{
					size += lpointer -> size;
					if (lpointer -> size >= alloc) // 左侧成功分配
					{
						lpointer -> size -= alloc;
						printf("%d\n", lpointer -> size);
						if (lpointer -> size == 0) // 节点移除
						{
							lpointer -> right -> left = lpointer -> left;
							lpointer -> left -> right = lpointer -> right;
							free(lpointer);
						}
						break;
					}
					if (rpointer -> size >= alloc) // 右侧成功分配
					{
						rpointer -> size -= alloc;
						printf("%d\n", rpointer -> size);
						if (rpointer -> size == 0) // 节点移除
						{
							rpointer -> right -> left = rpointer -> left;
							rpointer -> left -> right = rpointer -> right;
							free(rpointer);
						}
						break;
					}
					lpointer = lpointer -> left; // 指针转移 
					rpointer = rpointer -> right;
				}
				
				
				if (lpointer == head) // 到达头节点时需要合并内存
				{
					mergedsize = size;
					if (mergedsize >= alloc)
					{
						mergedsize -= alloc;
						printf("%d\n", mergedsize);
					}
					else printf("memory out\n");
				}
			}
		}
		
		
		else // 已经进行过内存合并则执行 
		{
			if (mergedsize >= alloc)
			{
				mergedsize -= alloc;
				printf("%d\n", mergedsize);
			}
			else printf("memory out\n");
		}
	}
}




