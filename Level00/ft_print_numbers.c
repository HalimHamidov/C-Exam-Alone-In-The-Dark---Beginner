#include <unistd.h>

void    ft_print_numbers(void)
{
    char n;
    
    n = '0';
    while (n <= '9')
    {
        write(1, &n, 1);
        n++;
    }
    write(1, "\n", 1);
}

int main(void)
{
    ft_print_numbers();
    return (0);
}


//Assignment name  : ft_print_numbers
//Expected files   : ft_print_numbers.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a function that displays all digits in ascending order.
//
//Your function must be declared as follows:
//
//void    ft_print_numbers(void);
//

