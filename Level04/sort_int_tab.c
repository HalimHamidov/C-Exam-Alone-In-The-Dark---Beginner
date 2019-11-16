#include <stdio.h>
#include <stdlib.h>

unsigned int    ft_strlen(int *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}
void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j;
	int temp;

	while ( i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
void    print(int *tab)
{
    int i;
    i = 0;
    while (tab[i])
    {
        printf("[%d] - ", tab[i]);
        i++;
    }
}
int        main(void)
{
    int *tab;
    
    if (!(tab = (int*)malloc(sizeof(int) * 10 + 1)))
        return (0);
    tab[0] = 7;
    tab[1] = 5;
    tab[2] = 4;
    tab[3] = 2;
    tab[4] = 4;
    tab[5] = 4;
    tab[6] = 4;
    tab[7] = 4;
    tab[8] = 3;
    tab[9] = 2;
    tab[10] = '\0';
    sort_int_tab(tab, ft_strlen(tab));
    print(tab);
    return (0);
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
