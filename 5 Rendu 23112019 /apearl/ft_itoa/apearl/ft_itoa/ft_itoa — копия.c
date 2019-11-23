#include <stdlib.h>
#include <stdio.h>
int nbrlen(unsigned int nbr, int len)
{
    while (nbr > 0)
    {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int nbr)
{
    char *res;
    int len;
    unsigned int nb;
    char *str;
    
    len = 0;
    str = "0123456789";
    nb = nbr < 0 ? -nbr : nbr;
    len = nbr < 0 ? 1 : len;
    len = nbrlen(nb, len);
    len = (nbr == 0) ? 1 : len;
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (nb == 0)
        res[0] = '0';
    res[len] = '\0';
    while (nb > 0)
    {
        res[--len] = str[nb % 10];
        nb = nb / 10;
    }
    if (nbr < 0)
        res[0] = '-';
    return (res);
}

 int main (int ac, char **av)
 {
 if (ac == 2)
 {
 printf("%s", ft_itoa(atoi(av[1])));
 }
 printf("\n");
 return 0;
 }
 
//int main()
//{
//    printf("%s\n", ft_itoa(0));
//    printf("%s\n", ft_itoa(9));
//    printf("%s\n", ft_itoa(-9));
//    printf("%s\n", ft_itoa(10));
//    printf("%s\n", ft_itoa(-10));
//    printf("%s\n", ft_itoa(8124));
//    printf("%s\n", ft_itoa(-9874));
//    printf("%s\n", ft_itoa(543000));
//    printf("%s\n", ft_itoa(-2147483648LL));
//    printf("%s\n", ft_itoa(2147483647));
//    return (0);
//}

