#include <stdlib.h>

char *ft_itoa_base(int value, int base)
{
    static  char rep[] = "0123456789abcdef";
    static  char buf[50];
    char    *ptr;
    int     num;
    
    ptr = &buf[49];
    *ptr = '\0';
    num = value;
    if (value < 0 && base == 10)
        value *= -1;
    if (value == 0)
        *--ptr = rep[value % base];
    while (value != 0)
    {
        *--ptr = rep[value % base];
        value /= base;
    }
    if (num < 0 && base == 10)
        *--ptr = '-';
    return (ptr);
}

#include <stdio.h>

int main (int ac, char **av)
{
	if (ac == 3)
	{
		printf("%s",ft_itoa_base(atoi(av[1]), atoi(av[2])));
	}
	return (0);
}
//
//Assignment name  : ft_itoa_base
//Expected files   : ft_itoa_base.c
//Allowed functions: malloc
//--------------------------------------------------------------------------------
//
//Write a function that converts an integer value to a null-terminated string
//using the specified base and stores the result in a char array that you must
//allocate.
//
//The base is expressed as an integer, from 2 to 16. The characters comprising
//the base are the digits from 0 to 9, followed by uppercase letter from A to F.
//
//For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".
//
//If base is 10 and value is negative, the resulting string is preceded with a
//minus sign (-). With any other base, value is always considered unsigned.
//
//Your function must be declared as follows:
//
//char    *ft_itoa_base(int value, int base);


//il-g5% ./itoa_base 21 2
//10101%                                                                                      il-g5% ./itoa_base 65 98
//(null)%                                                                                     il-g5% ./itoa_base 23 98
//(null)%                                                                                     il-g5% ./itoa_base 1 98
//(null)%                                                                                     il-g5% ./itoa_base 1 18
//(null)%                                                                                     il-g5% ./itoa_base 0 1
//(null)%                                                                                     il-g5% ./itoa_base 21 3
//210%                                                                                        il-g5% ./itoa_base 21 2
//10101%                                                                                      il-g5% ./itoa_base 2147483648 2
//10000000000000000000000000000000%                                                           il-g5% ./itoa_base 2147483647 2
//1111111111111111111111111111111%                                                            il-g5% ./itoa_base -2147483647 2
//1111111111111111111111111111111%                                                            il-g5% ./itoa_base -2147483648 2
//10000000000000000000000000000000%                                                           il-g5% ./itoa_base 1 17
//(null)%                                                                                     il-g5% ./itoa_base 1 16
//1%                                                                                          il-g5%

