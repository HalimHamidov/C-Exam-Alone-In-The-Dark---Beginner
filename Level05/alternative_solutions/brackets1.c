#include <unistd.h>

int    braclose(char *str, char c, int i, int b)
{
    while (b && *(++str) && (i++))
        if (*str == c || *str == c + c % 2 + 1)
            *str == c ? ++b : --b;
    return (i);
}

int    brackets(char *str, char c)
{
    if (*str == c)
        return (1);
    else if (!*str || *str == ')' || *str == '}' || *str == ']')
        return (0);
    else if (*str == '(' || *str == '{' || *str == '[')
        return (brackets(str + 1, *str + *str % 2 + 1)
                * brackets(str + braclose(str, *str, 1, 1), c));
    else
        return (brackets(str + 1, c));
}

int    main(int ac, char **av)
{
    int    i;
    
    i = 0;
    if (ac > 1)
        while (++i < ac)
            brackets(av[i], 0) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
    else
        write(1, "\n", 1);
    return (0);
}
//
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

