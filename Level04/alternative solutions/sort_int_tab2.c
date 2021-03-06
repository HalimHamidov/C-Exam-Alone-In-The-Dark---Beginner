#include <stdio.h>
#include <stdlib.h>

void	print(int *tab)
{
	int i;
	i = 0;
	while (tab[i])
	{
		printf("[%d] - ", tab[i]);
		i++;
	}
}

unsigned int	ft_strlen(int *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	sort_int_tab(int *tab, unsigned int size)
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

int		main(void)
{
	int *tab;

	if (!(tab = (int*)malloc(sizeof(int) * 3 + 1)))
		return (0);
	tab[0] = 7;
	tab[1] = 5;
	tab[2] = 0;
	// tab[3] = 2;
	// tab[4] = 4;
	// tab[5] = 4;
	// tab[6] = 4;
	// tab[7] = 4;
	// tab[8] = 3;
	// tab[9] = 2;
	tab[3] = '\0';
	sort_int_tab(tab, ft_strlen(tab));
	print(tab);
	return (0);
}