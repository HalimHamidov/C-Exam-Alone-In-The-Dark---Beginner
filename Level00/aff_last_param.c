#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    else
    {
        while (argv[argc-1][i])
        {
            write(1, &argv[argc-1][i], 1);
            i++;
        }
    }
    return (0);
}

//#include <unistd.h>
//
//int main (int ac, char **av)
//{
//    int i = 0;
//    if (ac < 2)
//    {
//        write (1, "\n", 1);
//        return (0);
//    }
//    else
//        while (av[ac - 1][i])
//        {
//            write(1, &av[ac - 1][i++], 1);
//        }
//    write (1, "\n", 1);
//    return (0);
//}

//Assignment name  : aff_last_param
//Expected files   : aff_last_param.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes strings as arguments, and displays its last
//argument followed by a newline.
//
//If the number of arguments is less than 1, the program displays a newline.
//
//Examples:
//
//$> ./aff_last_param "zaz" "mange" "des" "chats" | cat -e
//chats$
//$> ./aff_last_param "j'aime le savon" | cat -e
//j'aime le savon$
//$> ./aff_last_param
//$


