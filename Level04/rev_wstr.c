
#include <unistd.h>

static int		print_last(const char *str, int len)
{
	int				i;

	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	i = 0;
	while (i <= len && str[len - i] != ' ' && str[len - i] != '\t')
		i++;
	write(1, str + len - i + 1, i);
	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	if (i < len)
		write(1, " ", 1);
	return (len - i);
}

int				main(int argc, char **argv)
{
	int				len;

	if (argc == 2)
	{
		len = 0;
		while (argv[1][len] != '\0')
			len++;
		len--;
		while (len > 0)
			len = print_last(argv[1], len);
	}
	write(1, "\n", 1);
	return (0);
}

//Assignment name  : rev_wstr
//Expected files   : rev_wstr.c
//Allowed functions: write, malloc, free
//--------------------------------------------------------------------------------
//
//Write a program that takes a string as a parameter, and prints its words in
//reverse order.
//
//A "word" is a part of the string bounded by spaces and/or tabs, or the
//begin/end of the string.
//
//If the number of parameters is different from 1, the program will display
//'\n'.
//
//In the parameters that are going to be tested, there won't be any "additional"
//spaces (meaning that there won't be additionnal spaces at the beginning or at
//        the end of the string, and words will always be separated by exactly one space).
//
//Examples:
//
//$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
//l'indifference de celui precede mepris du temps le$
//$> ./rev_wstr "abcdefghijklm"
//abcdefghijklm
//$> ./rev_wstr "il contempla le mont" | cat -e
//mont le contempla il$
//$> ./rev_wstr | cat -e
//$
//$>

