void    sort_in_tab(int *tab, unsigned int size)
{
    unsigned int i;
    int tmp;
    
    i = 0;
    if (size == 0)
        return ;
    while (i < size - 1)
    {
        if (tab[i] > tab[i + 1])
        {
            tmp = tab[i + 1];
            tab[i + 1] = tab[i];
            tab[i] = tmp;
            i = 0;
        }
        else
            i++;
    }
}

//
//Assignment name  : sort_int_tab
//Expected files   : sort_int_tab.c
//Allowed functions:
//--------------------------------------------------------------------------------
//
//Write the following function:
//
//void sort_int_tab(int *tab, unsigned int size);
//
//It must sort (in-place) the 'tab' int array, that contains exactly 'size'
//members, in ascending order.
//
//Doubles must be preserved.
//
//Input is always coherent.
//
/*
 #include <stdio.h>
 void print_arr(int arr[], int size)
 {
 for (int i = 0; i < size; i++)
 {
 printf(" %d", arr[i]);
 }
 printf("\n");
 }
 
 int main (void)
 {
 int arr[12] = {0 ,1, 3, 6, 2, 4, 1324, 16774, 9, 2, 1, 7};
 int size = sizeof(arr) / sizeof(arr[0]);
 sort_int_tab(arr, size);
 print_arr(arr, size);
 return 0;
 }
 */
