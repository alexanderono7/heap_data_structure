//Created by Alexander Ono
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "util.h"
int main()
{
    //variable declaration
    HEAP *heap = NULL;
    char c;
    int i, v, f, k, n;
    while (1)
    {
        c = nextCommand(&i, &v, &f, &k, &n);
        switch (c)
        {
        case 'S': //exit program
            printf("COMMAND: %c\n", c);
            if (heap != NULL)
            {
                delete[] heap->H;
                delete heap;
            }
                    
            exit(0);

        case 'C': //initialize new heap
            printf("COMMAND: %c %d \n", c, n);
            if (n < 0)
            {
                printf("Error: invalid heap capacity\n");
                break;
            }
            else
            {
                heap = Initialize(n);
            }
            break;

        case 'R': //read array from HEAPinput.txt
            printf("COMMAND: %c\n", c);
            if(heap == NULL)
            {
                printf("Error: heap not initialized\n");
            }
            else
            {
                heap = readFile(heap);
            }
            break;

        case 'W': //write current heap information to screen
            printf("COMMAND: %c\n", c);
            //ensure heap is initialized
            if (heap == NULL)
            {
                printf("Error: heap not initialized\n");
            }
            else
            {
                writeFile(heap);
            }
            break;

        case 'I': //insert elements of value k into heap, f=flag
            printf("COMMAND: %c %d %d\n", c, f, k);
            if (heap == NULL)
            {
                printf("Error: heap not initialized\n");
            }else if (f > 2 or f < 1)
            {
                printf("Error: invalid flag value\n");
            }
            else
            {
                heap = Insert(heap, f, k);
            }
            break;

        case 'D': //delete max value, f=flag
            printf("COMMAND: %c %d \n", c, f);
            if (heap == NULL)
            {
                printf("Error: heap not initialized\n");
            }else if(heap->size == 0){
                printf("Error: heap empty\n");
            }else if (f > 2 or f < 1)
            {
                printf("Error: invalid flag value\n");
            }
            else
            {
                int max = DeleteMax(heap, f);
                printf("Deleted max = %d\n",max);
            }
            break;

        case 'K': //for heap element at [index], increase its value to [value] ([value] should be larger than its original value), f=flag
            printf("COMMAND: %c %d %d %d\n", c, f, i, v);
            if (heap == NULL)
            {
                printf("Error: heap not initialized\n");
            }else if (f > 2 or f < 1)
            {
                printf("Error: invalid flag value\n");
            }else if (i == 0 or (i > heap->size))
            {
                printf("Error: invalid index\n");
            }
            else if (heap->H[i].key > v)
            {
                printf("Error: new key is smaller than current key\n");                
            }
            else
            {
                IncreaseKey(heap, f, i, v);
            }
            break;

        default:
            break;
        }
    }
    exit(0);
}
