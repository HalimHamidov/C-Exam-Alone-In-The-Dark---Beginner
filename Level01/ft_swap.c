#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
    int a = 8;
    int b = 10;
    ft_swap(&a, &b);
    printf("%d\n%d", a, b);
    return (0);
}

// Вывод:
//10
//8
