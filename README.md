# heap_project
This program demonstrates the usage and functions of a heap data structure in the C++ language.

to run:

    make
    
    ./run

Commands:

    S  =  stop/kill program
    
    C n  =  Initialize(n)
    
            return heap object with capacity n and size 0
            
    R  =  read array from HEAPinput.txt
    
    W  =  writes current heap information to screen
    
    I f k  =  Insert(heap, flag, k)  
    
            insert element of value k into heap, f = flag. 
            
            f=1 no printing. f=2 print heap before and after insertion
            
    D f  =  DeleteMax(heap, flag)
    
            delete max value
            
            f=flag
            
            flag=1 no printing
            
            flag=2 print heap before & after deletion
            
    K f i v  =  IncreaseKey(heap, flag, index, value)
    
            for heap element at [index], increase its value to [value] ([value] should be larger than its original value)
            
            flag=1 no print
            
            flag=2 print heap before/after increasing an element value    
