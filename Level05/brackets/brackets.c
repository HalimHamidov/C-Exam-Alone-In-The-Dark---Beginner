#include <unistd.h>

int		matching(char b1, char b2)
{
	if (b1 == '(' && b2 == ')')
		return (1);
	if (b1 == '[' && b2 == ']')
		return (1);
	if (b1 == '{' && b2 == '}')
		return (1);
	return (0);
}

int		brackets(char *str, char *stack)
{
	int i;
	int top;

	i = 0;
	top = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			top++;
			stack[top] = str[i];
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (!stack[top])
				return (0);
			else if (!matching(stack[top], str[i]))
				return (0);
			else
			{
				stack[top] = 0;
				top--;
			}
		}
		i++;
	}
	if (stack[top] == 0)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int	 i;
	char stack[512];

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (brackets(av[i], stack))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1, "\n", 1);
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
//$>

