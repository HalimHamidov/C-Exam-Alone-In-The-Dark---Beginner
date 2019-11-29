#include <stdlib.h>
#include <stdio.h>

int ft_nlen(long n, int len)
{
    while (n > 0)
    {
        n = n/10;
        len++;
    }
    return (len);
}

char *ft_itoa(int nbr)
{
    long n;
    char *res;
    int len;
    char *str;
    
    str = "0123456789";
    len = nbr < 0 ? 1 : 0;
    n = nbr < 0 ? -(long)nbr : nbr;
    len = ft_nlen(n, len);
    len = (nbr == 0) ? 1 : len;
    if (!(res = (char *)malloc(sizeof(char)*(len+1))))
        return (NULL);
    if (nbr < 0)
        res[0] = '-';
    if (nbr == 0)
        res[0] = '0';
    res[len] = '\0';
    while (n > 0)
    {
        res[--len] = str[n % 10];
        n = n/10;
    }
    return (res);
}

int main()
{
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(9));
    printf("%s\n", ft_itoa(-9));
    printf("%s\n", ft_itoa(10));
    printf("%s\n", ft_itoa(-10));
    printf("%s\n", ft_itoa(8124));
    printf("%s\n", ft_itoa(-9874));
    printf("%s\n", ft_itoa(543000));
    printf("%s\n", ft_itoa(-2147483648LL));
    printf("%s\n", ft_itoa(2147483647));
    return (0);
}