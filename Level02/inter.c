
#include <unistd.h>

void ft_inter(char *a, char *b)
{
	int i = 0;
	char arr[127];
	while (b[i])
	{
		arr[(int)b[i]] = 1;
		i++;	
	}
	i = 0;
	while (a[i])
	{
		if(arr[(int)a[i]])
		{
			write(1, &a[i], 1);
			arr[(int)a[i]] = 0;
		}
		i++;
	}
}

int main (int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);
	}
	write (1, "\n", 1);
	return (0);
}

//Assignment name  : inter
//Expected files   : inter.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes two strings and displays, without doubles, the
//characters that appear in both strings, in the order they appear in the first
//one.
//
//The display will be followed by a \n.
//
//If the number of arguments is not 2, the program displays \n.
//
//Examples:
//
//$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
//padinto$
//$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
//df6ewg4$
//$>./inter "rien" "cette phrase ne cache rien" | cat -e
//rien$
//$>./inter | cat -e
//$

