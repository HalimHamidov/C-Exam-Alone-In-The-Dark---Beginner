//ft_putstr # puts string on std-out.

#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int    i;
    
    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int        main()
{
    ft_putstr("lorem ipsum dolor sit amet");
    write(1, "\n", 1);
    ft_putstr("  lorem\nipsum\rdolor\tsit amet  ");
    write(1, "\n", 1);
    ft_putstr("");
    ft_putstr("lorem ipsum do\0lor sit amet");
    write(1, "\n", 1);
    return (0);
}

// ft_putstr
// Prototype
// void ft_putstr(charconst*s);
// Description
// Outputs the string s to the standard output.
// Param. #1
// The string to output.
// Return value
// None.
// Libc functions
// write(2).
