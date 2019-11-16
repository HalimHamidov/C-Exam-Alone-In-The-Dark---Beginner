#include <unistd.h>

int ft_atoi(char *str) 
{
	int i = 0;
   	int nb = 0;
	while ( str[i] != 0 && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
    return (nb);
}
void print_hex(int x)
{
    char *base = "0123456789abcdef";

    if (x >= 16)
        print_hex(x/16);
    write (1, &base[x%16], 1);
}
int main (int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write (1, "\n" ,1);
	return (0);
}


//
//Assignment name  : print_hex
//Expected files   : print_hex.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes a positive (or zero) number expressed in base 10,
//and displays it in base 16 (lowercase letters) followed by a newline.
//
//If the number of parameters is not 1, the program displays a newline.
//
//Examples:
//
//$> ./print_hex "10" | cat -e
//a$
//$> ./print_hex "255" | cat -e
//ff$
//$> ./print_hex "5156454" | cat -e
//4eae66$
//$> ./print_hex | cat -e
//$

base[5156454%16] = 6
base[322278%16] = 6
base[20142%16] = e
base[1258%16] = a
base[78%16] = e 
base[4%16] = 4
5156454%16 = 6
322278%16 = 6
20142%16 = 14
1258%16 = 10
78%16 = 14
base[0] = 0
base[1] = 1
base[2] = 2
base[3] = 3
base[4] = 4
.
base[15] = f
base[16] = \0
