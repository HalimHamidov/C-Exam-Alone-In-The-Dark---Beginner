#include "unistd.h"

void ft_print_hex(int x) // Hexadecimal value of int 
{
	char *base = "0123456789abcdef";

	write(1, &base[x / 16], 1);
	write (1, &base[x % 16], 1);
}


void ft_putchar(char c) // Ascii value of int
{
	if (c >= 32 && c <= 126) // printable Ascii
		write(1, &c, 1);
	else
		write (1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i = 0; // counter for size
	size_t j; // counter for each 16 bytes

	unsigned char const *p = addr;

	while (i < size)
	{
		j = 0;
		while ( j < 16 && i + j < size) // to print each Byte at a time. 
		{
			ft_print_hex(*(p + i + j));
			if (j % 2)
				write (1, " ", 1);
			j++;
		}
		while ( j < 16) // to print the unitilized int's
		{
			write (1, "  ", 2);
			if (j % 2)
				write (1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size) // to print the Ascii values of the given it
		{
			ft_putchar(*(p + i + j));
			j++;
		}
		write (1, "\n", 1);
		i += 16;
	}
}


//#IMP Notes: 
//The main concept of print memory is to print each byte at a time because memory in real is always store in the cpu by the token of bytes.

//Assignment name  : print_memory
//Expected files   : print_memory.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a function that takes (const void *addr, size_t size), and displays the
//memory as in the example.
//
//Your function must be declared as follows:
//
//void    print_memory(const void *addr, size_t size);
//
//---------
//$> cat main.c
//void    print_memory(const void *addr, size_t size);
//
//int    main(void)
//{
//    int    tab[10] = {0, 23, 150, 255,
//        12, 16,  21, 42};
//    
//    print_memory(tab, sizeof(tab));
//    return (0);
//}
//$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e
//0000 0000 1700 0000 9600 0000 ff00 0000 ................$
//0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$
//0000 0000 0000 0000                     ........$

