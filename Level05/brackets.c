#include <unistd.h>

#define MATCH(a, b) ((a == ')' && b == '(') || (a == ']' && b =='[') || (a == '}' && b == '{'))

int ft_strlen(char *str);
int brackets(char *str);

int main(int argc, char **argv)
{
    int i;
    
    i = 1;
    if (argc < 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    while (i < argc)
    {
        if (brackets(argv[i]) == -1)
            write (1, "Error\n", 6);
        else
            write (1, "OK\n", 3);
        i++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
        i++;
    return (i);
}

int brackets(char *str)
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

// '(toto)'  // 1
// '([)]'  // 2
// '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}'  // 3
// '()' '[]' '{}' '' 'toto' '([{}[{(()[])}()]]())(((([])))())'  // 4 
// '()[]{}' '([{}])[({})]{([])}'  // 5 
// '(]' '{)' '[}' ')' '}' ')' '(' '{' '['  // 6

// Moulinette's tests
// il-c2% gcc brackets.c -g -o brackets                 
// il-c2% ./brackets '(toto)'
// OK
// il-c2% ./brackets '([)]'  
// Error
// il-c2% ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' 
// OK
// OK
// il-c2% ./brackets '()' '[]' '{}' '' 'toto' '([{}[{(()[])}()]]())(((([])))())'
// OK
// OK
// OK
// OK
// OK
// OK
// il-c2% ./brackets '()[]{}' '([{}])[({})]{([])}'
// OK
// OK
// il-c2% ./brackets '(]' '{)' '[}' ')' '}' ')' '(' '{' '[' 
// Error
// Error
// Error
// Error
// Error
// Error
// Error
// Error
// Error
