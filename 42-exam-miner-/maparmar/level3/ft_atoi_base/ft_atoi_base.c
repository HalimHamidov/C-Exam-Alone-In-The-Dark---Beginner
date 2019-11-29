#include <stdio.h>

#define abs(x) x < 0 ? -x : x

int is_correct(char c) // check if the char is vallid
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int		ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	unsigned int nb = 0;
	
	while (str[i] == ' ') // check if there is a space 
		i++;
	if (str[i] == '-' || str[i] == '+') // if it's negative or positive 
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (is_correct(str[i]) && (str_base <= 16) && str[i] != 0) // valid base and correct char 
	{
		if(str[i] >= '0' && str[i] <= '9')
			nb = nb *str_base + str[i] - '0';
		if ((str[i] >= 'A' && str[i] <= 'F') && (abs(str_base) >= 11)) // when its a bigger case
			nb = nb *str_base + str[i] - 'A' + 10;
		if ((str[i] >= 'a' && str[i] <= 'z') && (abs(str_base) >= 11)) // when its a smaller case
			nb = nb *str_base + str[i] - 'a' + 10;
		i++;
	}
	return (nb * sign);
}

int    main (void)
{
    char str[] = "12fdb3";
    int base = 10;
    
    printf("%d\n", ft_atoi_base(str, base));
    return (0);
}
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
