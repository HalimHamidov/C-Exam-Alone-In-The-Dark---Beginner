#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int    *r;
    int    len;
    
    if (end >= start)
        len = end - start + 1;
    else
        len = start - end + 1;
    if (!(r = (int*)malloc(sizeof(int) * len)))
        return (NULL);
    while (len--)
    {
        if (end >= start)
            r[len] = end--;
        else
            r[len] = end++;
    }
    return (r);
}


int main (void)
{
    int i = 0;
    int *result = ft_range(1, 10);
    while(i < 10)
    {
        printf("%d ", result[i]);
        i++;
    }
    printf("\n");
    return (0);
}

// //Assignment name  : ft_range
// //Expected files   : ft_range.c
// //Allowed functions: malloc
// //--------------------------------------------------------------------------------
// //
// //Write the following function:
// //
// //int     *ft_range(int start, int end);
// //
// //It must allocate (with malloc()) an array of integers, fill it with consecutive
// //values that begin at start and end at end (Including start and end !), then
// //return a pointer to the first value of the array.
// //
// //Examples:
// //
// //- With (1, 3) you will return an array containing 1, 2 and 3.
// //- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// //- With (0, 0) you will return an array containing 0.
// //- With (0, -3) you will return an array containing 0, -1, -2 and -3.
//r[0] = 1 = result[0]
//r[1] = 2 = result[1]
//r[2] = 3 = result[2]
