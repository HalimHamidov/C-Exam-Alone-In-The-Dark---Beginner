#include <stdlib.h>
#include <stdio.h>

int        is_number(char *c)
{
    if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%')
    {
        if (is_number(c + 1))
            return (1);
        else
            return (0);
    }
    if (*c >= '0' && *c<= '9')
        return (1);
    else
        return (0);
}

int        is_operator(char *c)
{
    if(*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%')
    {
        if (!is_number(c + 1))
            return (1);
        else
            return (0);
    }
    else
        return (0);
}

int        rpn_calc(char *str, int *result)
{
    char    *ptr;
    int        *tab;
    int        i;
    
    tab = (int *)malloc(sizeof(int) * 5000);
    i = -1;
    ptr = str;
    while (*ptr)
    {
        if (is_number(ptr))
        {
            i++;
            tab[i] = atoi(ptr);
            ptr++;
            while(is_number(ptr))
                ptr++;
        }
        if (is_operator(ptr))
        {
            if ((i - 1) < 0)
                return (-1);
            if (*ptr == '/' || *ptr == '%')
                if (tab[i] == 0)
                    return (-1);
            if (*ptr == '+')
                tab[i - 1] = tab[i - 1] + tab[i];
            if (*ptr == '-')
                tab[i - 1] = tab[i - 1] - tab[i];
            if (*ptr == '*')
                tab[i - 1] = tab[i - 1] * tab[i];
            if (*ptr == '/')
                tab[i - 1] = tab[i - 1] / tab[i];
            if (*ptr == '%')
                tab[i - 1] = tab[i - 1] % tab[i];
            i--;
        }
        ptr++;
    }
    *result = tab[0];
    if (i != 0)
        return (-1);
    else
        return (1);
}
int main(int ac, char **av)
{
    int    result;
    
    result = 0;
    if(ac != 2)
        printf("Error\n");
    else
    {
        if (rpn_calc(av[1], &result) == -1)
            printf("Error\n");
        else
            printf("%d\n", result);
    }
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

