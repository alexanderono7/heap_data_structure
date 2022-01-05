//Created by Alexander Ono
#include "util.h"
#include "heap.h"
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//read the values from ./HEAPinput.txt and store them in the argument heap object
HEAP *readFile(HEAP *heap)
{
    int s;
    string line;

    ifstream file("./HEAPinput.txt");
    //ensure file exists and is readable
    if (!file.is_open())
    {
        printf("Error: Please ensure that HEAPinput.txt is in the current directory and has readability permissions.\n");
    }
    else
    {
        getline(file, line);
        s = std::stoi(line); //n = number of elements in array. Cast string to integer with stoi.
        //ensure that input file's data size doesn't exceed heap capacity
        if (s > heap->capacity)
        {
            printf("Error: array size exceeds heap capacity\n");
        }
        else
        {
            //proceed to reading/storing all list elements of input file
            heap->size = s;
            int i = 1;
            while (getline(file, line))
            {
                heap->H[i].key = std::stoi(line);
                ++i;
            }
        }
        heap = BuildHeap(heap);
        return heap;
    }

    //return null if one of the conditions failed
    return NULL;
}

//print heap object values to screen
void writeFile(HEAP *heap)
{
    printf("Capacity = %d\n", heap->capacity);
    printf("Size = %d\n", heap->size);
    for (int i = 1; i < heap->size + 1; i++)
    {
        printf("%d\n", heap->H[i].key);
    }
}

//allocate memory for a new heap object with 'n' capacity and size=0 & return its pointer (newHeap)
HEAP *Initialize(int n)
{
    HEAP *newHeap = new HEAP; //newHeap is pointer to new heap object created
    newHeap->capacity = n;
    newHeap->size = 0;
    newHeap->H = new ELEMENT[n + 1]; //pointer H in Heap object now points to a memory-allocated array of n size. n+1 is the size because we are not going to use the 0 index
    return newHeap;
}

// copy the elements of A into heap->H
// build a max heap in linear time of size n
HEAP *BuildHeap(HEAP *heap)
{
    for (int i = heap->size; i > 0; --i)
    {
        MaxHeapify(heap->H, i, heap->size);
    }

    return heap;
}

//maintain heap property; "float" any offending nodes down the tree
//return ELEMENT[]
void MaxHeapify(ELEMENT *A, int i, int size)
{
    int l = i * 2;
    int r = i * 2 + 1;
    int largest = INT_MIN;
    if (l <= size and (A[l].key > A[i].key))
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= size and A[r].key > A[largest].key)
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = A[i].key;
        A[i].key = A[largest].key;
        A[largest].key = temp;
        MaxHeapify(A, largest, size);
    }
}

//insert element 'key' into heap at 'i'. if f = 2 then print the heap contents
HEAP *Insert(HEAP *heap, int flag, int key)
{
    if (flag == 2)
    {
        printf("Before insert operation:\n");
        writeFile(heap);
    }

    //increase heap capacity to be at max row value
    heap->size++;
    int t = 1;
    while (t < heap->size)
    {
        t *= 2;
    }
    if (heap->capacity < t)
    {
        heap->capacity = t;
    }

    //insert element and maintain heap property
    int i = heap->size;
    while (i > 1 and (heap->H[parent(i)].key < key))
    {
        heap->H[i].key = heap->H[parent(i)].key;
        i = parent(i);
    }
    heap->H[i].key = key;

    if (flag == 2)
    {
        printf("After insert operation:\n");
        writeFile(heap);
    }
    return heap;
}

//for int i in the array, increase its value to 'key' and then reaffirm the heap property.
void IncreaseKey(HEAP *heap, int flag, int i, int key)
{
    if (flag == 2)
    {
        printf("Before increase key operation:\n");
        writeFile(heap);
    }

    heap->H[i].key = key;
    while (i > 1 and (heap->H[parent(i)].key < heap->H[i].key))
    {
        //swap values
        int temp = heap->H[parent(i)].key; 
        heap->H[parent(i)].key = heap->H[i].key;
        heap->H[i].key = temp;

        i = parent(i);
    }
    
    if (flag == 2)
    {
        printf("After increase key operation:\n");
        writeFile(heap);
    }
}

//return parent of current element
int parent(int i)
{
    int p;
    p = floor((double)i / 2);
    return p;
}

//delete largest element of the heap and return it
int DeleteMax(HEAP* heap, int flag)
{
    if (flag == 2)
    {
        printf("Before delete max operation:\n");
        writeFile(heap);
    }

    int max = heap->H[1].key;
    heap->H[1].key = heap->H[heap->size].key;
    heap->size--;
    MaxHeapify(heap->H, 1, heap->size);

    if (flag == 2)
    {
        printf("After delete max operation:\n");
        writeFile(heap);
    }
    return max;
}
