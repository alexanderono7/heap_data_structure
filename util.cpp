#include <ctype.h>
#include "util.h"
//=============================================================================
int nextCommand(int *i, int *v, int *f, int *k, int *n)
{
    char c;
    while (1)
    {
        scanf("%c", &c);
        c = toupper(c);

        //whitespace entered
        if (c == ' ' || c == '\t' || c == '\n')
        {
            continue;
        }

        //kill program
        //read from file
        //print heap to screen
        if (c == 'S' || c == 'R' || c == 'W')
        {
            break;
        }

        //create new heap object
        if (c == 'c' || c == 'C')
        {
            scanf("%d", n);
            break;
        }

        //insert key
        //insert element of value k into heap, f = flag.
        //f=1 no printing. f=2 print heap before and after insertion
        if (c == 'i' || c == 'I')
        {
            scanf("%d", f);
            scanf("%d", k);
            break;
        }

        //Delete maximum
        //remove max value from heap object
        //flag=1 no print, flag=2 print before/after
        if (c == 'D' || c == 'd')
        {
            scanf("%d", f);
            break;
        }

        //increase key
        //for heap element at [index], increase its value to [value] ([value] should be larger than its original value)
        //flag=1 no print, flag=2 print before/after
        if (c == 'K' || c == 'k')
        {
            scanf("%d", f);
            scanf("%d", i);
            scanf("%d", v);
            break;
        }

        // if (c == '' || c == '')
        // {
        //     scanf("%d", f);
        //     break;
        // }
        // if ()
        // {
        //     ...
        // }
        printf("Invalid Command\n");
    }
    return c;
}