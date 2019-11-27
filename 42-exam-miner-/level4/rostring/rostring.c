
#include <unistd.h>

int main (int ac , char **av)
{
	int i = 0;
	int j;

	if (ac >= 2)
	{
		
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t')) // search for is_space and move the position.
			{
				i++;
			}
			j = i; // this is the postion of starting of the word.
			while (av[1][i])
			{
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t')) // find the next word.
				{
					i++;
				}
				while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t')) // find the next word.
				{
					i++;
				}
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t') && (av[1][i -1] == ' ' || av[1][i - 1] == '\t')) // print the word till it reaches last.
				{
					while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
					{
						write (1, &av[1][i], 1);
						i++;
					}
					write (1, " ", 1);
					i++;
				}
			}
			while (av[1][j] && (av[1][j] != ' ' && av[1][j] != '\t')) // print the first word now.
			{
				write (1, &av[1][j], 1);
				j++;
			}
	}
	write (1, "\n", 1);
}

//Assignment name  : rostring
//Expected files   : rostring.c
//Allowed functions: write, malloc, free
//--------------------------------------------------------------------------------
//
//Write a program that takes a string and displays this string after rotating it
//one word to the left.
//
//Thus, the first word becomes the last, and others stay in the same order.
//
//A "word" is defined as a part of a string delimited either by spaces/tabs, or
//by the start/end of the string.
//
//Words will be separated by only one space in the output.
//
//If there's less than one argument, the program displays \n.
//
//Example:
//
//$>./rostring "abc   " | cat -e
//abc$
//$>
//$>./rostring "Que la      lumiere soit et la lumiere fut"
//la lumiere soit et la lumiere fut Que
//$>
//$>./rostring "     AkjhZ zLKIJz , 23y"
//zLKIJz , 23y AkjhZ
//$>
//$>./rostring | cat -e
//$
//$>
//
