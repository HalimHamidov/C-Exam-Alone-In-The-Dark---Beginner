#include <unistd.h>

void    putchar(int c)
{
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    int i;
    
    i = -1;
    if (ac == 2)
    {
        while(av[1][++i])
        {
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                putchar('_');
                putchar(av[1][i] + 32);
            }
            else
                putchar(av[1][i]);
        }
    }
    putchar('\n');
    return (0);
}
//Assignment name  : camel_to_snake
//Expected files   : camel_to_snake.c
//Allowed functions: malloc, free, realloc, write
//--------------------------------------------------------------------------------
//
//Write a program that takes a single string in lowerCamelCase format
//and converts it into a string in snake_case format.
//
//A lowerCamelCase string is a string where each word begins with a capital letter
//except for the first one.
//
//A snake_case string is a string where each word is in lower case, separated by
//an underscore "_".
//
//Examples:
//$>./camel_to_snake "hereIsACamelCaseWord"
//here_is_a_camel_case_word
//$>./camel_to_snake "helloWorld" | cat -e
//hello_word$
//$>./camel_to_snake | cat -e
//$

