struct ELEMENT
{
    int key;
};
struct HEAP
{
    int capacity;
    int size;
    ELEMENT *H;
};

void writeFile(HEAP *heap);
HEAP *readFile(HEAP *heap);
HEAP *Initialize(int n);
void printHeap(HEAP *heap);
HEAP *BuildHeap(HEAP *heap);
void MaxHeapify(ELEMENT *A, int i, int size);
HEAP *Insert(HEAP *heap, int flag, int key);
void IncreaseKey(HEAP *heap, int f, int i, int key);
int parent(int i);
int DeleteMax(HEAP* heap, int flag);