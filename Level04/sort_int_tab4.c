#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned	a = 0;
	unsigned	i = 0;

	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			a = i;
		}
		while (a)
		{
			if (tab[a - 1] > tab[a])
			{
				ft_swap(&tab[a - 1], &tab[a]);
				--a;
			}
			else
				a = 0;
		}
		++i;
	}
}

int		main(void)
{
	int a[6] = {9, 7, 6, 0, 5, 10};
	int i = 0;
	int size = 6;

	sort_int_tab(a, size);
	while (i < size)
		printf("%d ", a[i++]);
	return (0);
}