#include <stdlib.h>
//#define abs(v) (v) < 0 ? -(v) : (v) // abs function to calculate the Absolute value

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		abs(int v)
{
	return (v < 0 ? (-v) : (v));
}

void ib(int n, int b, char *res, int *p)
{
	char *str = "0123456789ABCDEF"; // маска

	if (n >= b || n <= -b) // recursive call for the function
		ib(n / b, b, res, p);
	res[(*p)++] = str[abs(n % b)]; 
}

// // 12345 10

// // 12345 / 10 = 1234  10

// // 1234 10
// // 1234 / 10 = 123 10

// // 123 10
// // 123 / 10 = 12 10

// // 12 10
// // 12 / 10 = 1 10

// // 1 10

// // p = 1
// // res[1] = str[1];

// // res = "1 _ _ _ _"

// // p = 2
// // res[2] = str[2]

// // res = "1 2 _ _ _"

// // p = 3
// // res[3] = str[3]
// // res = "1 2 3 _ _"


// // ...
// // res = "12345";

//
//21 2 |
//21 / 2 = 10 2        21 % 2 = 1
//10 / 2 = 5 2        10 % 2 = 0
//5 / 2 = 2            5 % 2 = 1
//2 / 2 = 0            2 % 2 = 0
//                            1
//p = 1    res[1] = 1
//p = 1    res[1] = 0
//p = 2    res[2] = 1
//p = 3    res[3] = 0
//p = 4    res[4] = 1
//
//10101
//



char *ft_itoa_base(int value, int base)
{
	int p = 0;
	char *res;

	if (((base < 2 || base > 16) || !(res = (char *)malloc(sizeof(char) * 35)))) // maximum length needed in the condition --> waste of memory
		return NULL;
	if (value < 0 && base == 10)
		res[p++] = '-';
	ib(value, base, res, &p);
	res[p] = '\0';
	return (res);
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

