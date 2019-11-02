#include <unistd.h>

int ft_check(char *str, int len, char c);

int main(int argc, char **argv)
{
    int i;
    int j;
    i = 0;
    if (argc != 3)
    {
        write (1, "\n", 1);
        return (0);
    }
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (ft_check(argv[1], i, argv[1][i]))
                write(1, &argv[1][i], 1);
            i++;
        }
        
        j = 0;
        while (argv[2][j])
        {
            if (ft_check(argv[2], j, argv[2][j]) && ft_check(argv[1], i, argv[2][j]))
                write(1, &argv[2][j], 1);
            j++;
        }
    }
    return (0);
}

int ft_check(char *str, int len, char c)
{
    int n;
    
    n = 0;
    while (n < len)
    {
        if (str[n] == c)
            return (0);
        n++;
    }
    return (1);
}

//Assignment name  : union
//Expected files   : union.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes two strings and displays, without doubles, the
//characters that appear in either one of the strings.
//
//The display will be in the order characters appear in the command line, and
//will be followed by a \n.
//
//If the number of arguments is not 2, the program displays \n.
//
//Example:
//
//$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
//zpadintoqefwjy$
//$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
//df6vewg4thras$
//$>./union
//rienct phas$
//$>./union | cat -e
//$
//$>
//$>./union "rien" | cat -e
//$
//$>

