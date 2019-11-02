#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    
    i = 0;
    while(argv[0][i])
    {
        write (1, "z\n", 2);
        return (0);
    }
    return (0);
}

//#include <unistd.h>
//
//int main (int argc, char **argv)
//{
//    if (argc > 0 && argv[0] > 0)
//    {
//        write (1, "z\n", 2);
//    }
//    return (0);
//}

//#include <unistd.h>
//
//int        main(int ac, char **av)
//{
//    (void)ac;
//    (void)av;
//    write(1, "z\n", 2);
//    return (0);
//}

//Assignment name  : aff_z
//Expected files   : aff_z.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes a string, and displays the first 'z'
//character it encounters in it, followed by a newline. If there are no
//'z' characters in the string, the program writes 'z' followed
//by a newline. If the number of parameters is not 1, the program displays
//'z' followed by a newline.
//
//Example:
//
//$> ./aff_z "abc" | cat -e
//z$
//$> ./aff_z "dubO a POIL" | cat -e
//z$
//$> ./aff_z "zaz sent le poney" | cat -e
//z$
//$> ./aff_z | cat -e
//z$


