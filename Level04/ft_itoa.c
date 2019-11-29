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
//int    main(void)
//{
//    int i = 0;
//    int tab[5] = {-2147483648, -42, 0, 42, 2147483647};
//
//    while (i < 5)
//        printf("%s\n", ft_itoa(tab[i++]));
//
//    return 0;
//}

// ft_itoa
// Prototype
// char* ft_itoa(intn);
// Description
// Allocate (with malloc(3)) and returns a “fresh” string end- ing with ’\0’ representing the integer n given as argument. Negative numbers must be supported. If the allocation fails, the function returns NULL.
// Param. #1
// The integer to be transformed into a string.
// Return value
// The string representing the integer passed as argument.
// Libc functions
// malloc(3)


//Assignment name  : ft_itoa
//Expected files   : ft_itoa.c
//Allowed functions: malloc
//--------------------------------------------------------------------------------
//
//Write a function that takes an int and converts it to a null-terminated string.
//The function returns the result in a char array that you must allocate.
//
//Your function must be declared as follows:
//
//char    *ft_itoa(int nbr);


//il-g5% ./ft_itoa
//0
//9
//-9
//10
//-10
//8124
//-9874
//543000
//-2147483648
//2147483647


