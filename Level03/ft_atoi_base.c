#include <stdio.h>
#include <stdlib.h>

int ft_isblank(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int        isvalid(char c, int base)
{
    char digits[17] = "0123456789abcdef";
    char digits2[17] = "0123456789ABCDEF";
    
    while (base--)
        if (digits[base] == c || digits2[base] == c)
            return (1);
    return (0);
}

int        value_of(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int        ft_atoi_base(const char *str, int str_base)
{
    int result;
    int sign;
    
    result = 0;
    while (ft_isblank(*str))
        str++;
    
    //sign = (*str == '-') ? -1 : 1;
    if (*str == '-')
        sign = -1;
    else
        sign = 1;
    
    //(*str == '-' || *str == '+') ? ++str : 0;
    if (*str == '-' || *str == '+')
        ++str;

    while (isvalid(*str, str_base))
        result = result * str_base + value_of(*str++);
    return (result * sign);
}

int        main(int ac, char **av)
{
    if (ac == 3)
        printf("result: %d\n", ft_atoi_base(av[1], atoi(av[2])));
    return (0);
}

//int    main (void)
//{
//    char str[] = "12fdb3";
//    int base = 10;
//
//    printf("%d\n", ft_atoi_base(str, base));
//    return (0);
//}

//Assignment name  : ft_atoi_base
//Expected files   : ft_atoi_base.c
//Allowed functions: None
//--------------------------------------------------------------------------------
//
//Write a function that converts the string argument str (base N <= 16)
//to an integer (base 10) and returns it.
//
//The characters recognized in the input are: 0123456789abcdef
//Those are, of course, to be trimmed according to the requested base. For
//example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
//
//Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
//
//Minus signs ('-') are interpreted only if they are the first character of the
//string.
//
//Your function must be declared as follows:
//
//int    ft_atoi_base(const char *str, int str_base);
//
//il-g5% ./a.out 12fdb3 1
//result: 0
//il-g5% ./a.out 12fdb3 2
//result: 1
//il-g5% ./a.out 12fdb3 3
//result: 5
//il-g5% ./a.out 12fdb3 4
//result: 6
//il-g5% ./a.out 12fdb3 5
//result: 7
//il-g5% ./a.out 12fdb3 6
//result: 8
//il-g5% ./a.out 12fdb3 7
//result: 9
//il-g5% ./a.out 12fdb3 8
//result: 10
//il-g5% ./a.out 12fdb3 9
//result: 11
//il-g5% ./a.out 12fdb3 10
//result: 12
//il-g5% ./a.out 12fdb3 11
//result: 13
//il-g5% ./a.out 12fdb3 12
//result: 14
//il-g5% ./a.out 12fdb3 13
//result: 15
//il-g5% ./a.out 12fdb3 14
//result: 16
//il-g5% ./a.out 12fdb3 15
//result: 17
//il-g5% ./a.out 12fdb3 16
//result: 1244595
//il-g5% ./a.out 12fdb3 17
//result: 1585175797
//il-g5% ./a.out 12fdb3 18
//result: -1882462428
//il-g5% ./a.out 12fdb3 19
//result: 1334937527
//il-g5% ./a.out 12fdb3 20
//result: -847871456

