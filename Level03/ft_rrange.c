#include <stdlib.h>

int     *ft_rrange(int start, int end)
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
            r[len] = start++;
        else
            r[len] = start--;
    }
    return (r);
}

#include <stdio.h>

int main (void)
{
    int i = 0;
    int *result = ft_rrange(1, 3);
    while(i < 3)
    {
        printf("%d ", result[i]);
        i++;
    }
    printf("\n");
    return (0);
}
// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.
// r[len] = (end >= start) ? start++ : start--;
//len = (end >= start) ? end - start + 1 : start - end + 1;

//r[0] = 3 = result[0]
//r[1] = 2 = result[1]
//r[2] = 1 = result[2]


