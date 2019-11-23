#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_nbrlen(long nbr, int len)
{
    while (nbr > 0)
    {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int nb)
{
    int nbr;
    char *res;
    char *str;
    int len;
    
    str = "0123456789";
    
    nbr = nb < 0 ? -(long)nb : nb;
    len = nb < 0 ? 1 : 0;
    len = (nb == 0) ? 1 : len;
    len = ft_nbrlen(nbr, len);


    if (!(res = (char *)malloc(sizeof(char)*(len + 1))))
        return (NULL);
    if (nb < 0)
        res[0] = '-';
    if (nb == 0)
        res[0] = '0';
    res[len] = '\0';
    while (nbr > 0)
    {
        res[--len] = str[nbr % 10];
        nbr = nbr / 10;
    }
    return (res);
}


int main(void)
{
    printf("%s\n", ft_itoa(9));
}


