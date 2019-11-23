void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    int tmp;
    i = 0;

    if (size == 0)
            return ;
    while (i < size - 1)
    {

        if (tab[i] > tab[i +1])
        {
            tmp = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = tmp;
            i = 0; // mistake
        }
        else 
            i++; // mistake
    }
}

// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.