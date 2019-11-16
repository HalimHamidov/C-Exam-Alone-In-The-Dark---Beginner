
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int	*r;
	int	len;

	len = (end >= start) ? end - start + 1 : start - end + 1;
	if (!(r = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	 while (len--)
		 r[len] = (end >= start) ? start++ : start--;
	return (r);
}

#include <stdio.h>
int main (void)
{
	int i = 0;
	int *result = ft_rrange(1, 4);
	while(i < 4)
	{
		printf("The value is %d\n", result[i]);
		i++;
	}
	return (0);
}
