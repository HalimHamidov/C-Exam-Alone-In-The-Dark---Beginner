#include <stdlib.h>

int nbrlen(long nbr, int len)
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
    int nb;
    char *str;
    
    len = 0;
    str = "0123456789";
    nb = nbr < 0 ? -(long)nbr : nbr;
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
