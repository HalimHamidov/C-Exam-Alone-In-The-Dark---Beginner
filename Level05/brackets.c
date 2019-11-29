// Passed Moulinette 2019.09.01

#include <unistd.h>

#define MATCH(a, b) ((a == ')' && b == '(') || (a == ']' && b == '[') || (a == '}' && b == '{'))

int	ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return (i);
}

int	brackets(char *str)
{
	int i = 0;
	int stack[ft_strlen(str)];

	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			stack[++i] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
		{
			if (MATCH(*str, stack[i]) == 0)
				return (-1);
			--i;
		}
		str++;
	}
	if (i != 0)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int i = 1;
	while (i < ac)
	{
		if (brackets(av[i]) == -1)
			write(1, "Error\n", 6);
		else
			write(1, "OK\n", 3);
		++i;
	}
	return (0);
}

//Assignment name  : brackets
//Expected files   : *.c *.h
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes an undefined number of strings in arguments. For each
//argument, the program prints on the standard output "OK" followed by a newline
//if the expression is correctly bracketed, otherwise it prints "Error" followed by
//a newline.
//
//Symbols considered as 'brackets' are brackets '(' and ')', square brackets '['
//and ']'and braces '{' and '}'. Every other symbols are simply ignored.
//
//An opening bracket must always be closed by the good closing bracket in the
//correct order. A string which not contains any bracket is considered as a
//correctly bracketed string.
//
//If there is no arguments, the program must print only a newline.
//
//Examples :
//
//$> ./brackets '(johndoe)' | cat -e
//OK$
//$> ./brackets '([)]' | cat -e
//Error$
//$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
//OK$
//OK$
//$> ./brackets | cat -e
//$

