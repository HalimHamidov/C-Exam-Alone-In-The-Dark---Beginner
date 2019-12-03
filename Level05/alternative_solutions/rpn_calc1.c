
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		operate(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
			return (0);
		return (a / b);
	}
	if (op == '%')
	{
		if (b == 0)
			return (0);
		return (a % b);
	}
	return (0);
}

int		isnum(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}

int		isop(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
		return (1);
	return (0);
}

int		rpn_calc(char *str, int *stack)
{
	int i;
	int top;

	i = 0;
	top = -1;
	while (str[i] != '\0')
	{
		if (isnum(&str[i]))
		{
			top++;
			stack[top] = atoi(&str[i]);
			while (str[i] != ' ' && str[i + 1] != '\0')
				i++;
		}
		if (isop(str[i]))
		{
			if (top > 0)
			{
				if ((stack[top - 1] = operate(stack[top - 1], stack[top],
				str[i])) == 0)
					return (write(1, "Error\n", 6));
				top--;
			}
			else
				return (write(1, "Error\n", 6));
		}
		i++;
	}
	if (top == 0)
		printf("%d\n", stack[top]);
	else
		write(1, "Error\n", 6);
	return (0);
}

int		main(int ac, char **av)
{
	int stack[512];

	if (ac == 2)
		rpn_calc(av[1], stack);
	else
		write(1, "Error\n", 6);
	return (0);
}


//Assignment name  : rpn_calc
//Expected files   : *.c, *.h
//Allowed functions: atoi, printf, write, malloc, free
//--------------------------------------------------------------------------------
//
//Write a program that takes a string which contains an equation written in
//Reverse Polish notation (RPN) as its first argument, evaluates the equation, and
//prints the result on the standard output followed by a newline.
//
//Reverse Polish Notation is a mathematical notation in which every operator
//follows all of its operands. In RPN, every operator encountered evaluates the
//previous 2 operands, and the result of this operation then becomes the first of
//the two operands for the subsequent operator. Operands and operators must be
//spaced by at least one space.
//
//You must implement the following operators : "+", "-", "*", "/", and "%".
//
//If the string isn't valid or there isn't exactly one argument, you must print
//"Error" on the standard output followed by a newline.
//
//All the given operands must fit in a "int".
//
//Examples of formulas converted in RPN:
//
//3 + 4                   >>    3 4 +
//((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -
//50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *
//
//Here's how to evaluate a formula in RPN:
//
//1 2 * 3 * 4 -
//2 3 * 4 -
//6 4 -
//2
//
//Or:
//
//3 1 2 * * 4 -
//3 2 * 4 -
//6 4 -
//2
//
//Examples:
//
//$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e
//10$
//$> ./rpn_calc "1 2 3 4 +" | cat -e
//Error$
//$> ./rpn_calc |cat -e
//Error$

