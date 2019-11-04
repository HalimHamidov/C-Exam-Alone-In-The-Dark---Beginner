#include <unistd.h>

void    wdmatch(char *a, char *b);

int main(int argc, char **argv)
{
    if (argc == 3)
        wdmatch(argv[1], argv[2]);
    write (1, "\n", 1);
    return (0);
}

void    wdmatch(char *a, char *b)
{
    int i,
    int j;
    i = 0;
    j = 0;
    while (a[i] && b[j])
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
            if (a[i] == '\0')
            {
                while(*a)
                    write (1, a++, 1);
                return ;
            }
        }
        else
            j++;
    }
}

//Assignment name  : wdmatch
//Expected files   : wdmatch.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes two strings and checks whether it's possible to
//write the first string with characters from the second string, while respecting
//the order in which these characters appear in the second string.
//
//If it's possible, the program displays the string, followed by a \n, otherwise
//it simply displays a \n.
//
//If the number of arguments is not 2, the program displays a \n.
//
//Examples:
//
//$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
//faya$
//$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
//$
//$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
//quarante deux$
//$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
//$
//$>./wdmatch | cat -e
//$


//#include <unistd.h>
//
//void ft_wdmatch(char *a, char *b)
//{
//    int i = 0;
//    int j = 0;
//
//    while ((a[i] && b[j]) != 0)
//    {
//        if (a[i] == b[j])
//        {
//            i++;
//            j++;
//            if (a[i] == '\0')
//            {
//                while (*a)
//                {
//                    write (1, a, 1);
//                    a++;
//                }
//                return ;
//            }
//        }
//        else
//            j++;
//    }
//}
//
//int main (int ac, char **av)
//{
//    if (ac == 3)
//    {
//        ft_wdmatch(av[1], av[2]);
//    }
//    write (1, "\n", 1);
//    return (0);
//}

