#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int i;
	int tmp;

	i = 1;
	while (i < len - 1)
	{
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (tab[0]);
}

int main(void)
{
    int    tab[] = {42, 0, 5, 64, 2, 68, 1};
    
    printf("max : %d", max(tab, 7));
    return (0);
}
