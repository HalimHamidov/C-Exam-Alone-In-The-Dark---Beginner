#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int nbrlen(unsigned int n, int len)
{
    int base;
    base = 10;
    while (n)
    {
        n = n / base;
        len++;
    }
    return (len);
}

char *ft_itoa(int nbr)
{
    unsigned int nb;
    int len;
    char *str;
    char *res;
    
    str = "0123456789";//
    nb = (nbr < 0) ? -(long)nbr : nbr;//
    len = (nbr < 0) ? 1 : 0;//
    len = nbrlen(nb, len);//
    if(!(res = (char *)malloc(sizeof(char)*(len+1))))//
        return (NULL);//
    if (nbr == 0)//
        res[0] = '0';//
    res[len] = '\0';//
    if (nbr < 0)//
        res[0] = '-';//
    while (nb)//
    {
        res[--len] = str[nb % 10];
        nb = nb / 10;
    }
    return (res);//
}


int main(void)
{
    printf("%s",ft_itoa(-7));
    return (0);
}

