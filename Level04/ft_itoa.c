#include <stdlib.h>
#include <stdio.h> //for main test

static int    ft_strlen(const char *s)
{
    int i;
    
    i = 0;
    while (s[i])
        i++;
    return i;
}

static char    *ft_strrev(char *str)
{
    int i;
    int j;
    int tmp;
    
    i = 0;
    j = ft_strlen(str);
    while (j > i)
    {
        j--;
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
    }
    return str;
}

char    *ft_itoa(int nbr)
{
    int i;
    int neg;
    char *tmp;
    
    i = 0;
    neg = 0;
    tmp = malloc(sizeof(char) * 12);
    if (tmp == NULL || nbr == 0)
        return ((nbr == 0) ? "0" : NULL);
    if (nbr == -2147483648)
        return ("-2147483648");
    if (nbr < 0)
    {
        neg = 1;
        nbr *= -1;
    }
    while (nbr)
    {
        tmp[i++] = (nbr % 10) + '0';
        nbr /= 10;
    }
    if (neg)
        tmp[i] = '-';
    return ft_strrev(tmp);
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


