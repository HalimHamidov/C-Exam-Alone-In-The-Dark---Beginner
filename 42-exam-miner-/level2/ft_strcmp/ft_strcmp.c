
#include <stdio.h>
int    ft_strcmp(char *s1, char *s2)
{
	while ((*s1 || *s2) != 0)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (*s1 - *s2);
	}
	return (0);
}
int main(void)
{
    // Сравниваемые строки
    char str1[1024]="12345";
    char str2[1024]="12345";
    
    // Сравниваем две строки
    if (ft_strcmp(str1, str2)==0)
        puts("Строки идентичны");
    else
        puts("Строки отличаются");
    printf("1/%d", ft_strcmp("salut", "salut"));
    printf("\n2/%d", ft_strcmp("test", "testss"));
    printf("\n3/%d", ft_strcmp("testss", "test"));
    printf("\n4/%d", ft_strcmp("test", "tEst"));
    printf("\n5/%d", ft_strcmp("", "test"));
    printf("\n6/%d", ft_strcmp("test", ""));
    printf("\n7/%d", ft_strcmp("test\200", "test\0"));//why the output is   128
}

