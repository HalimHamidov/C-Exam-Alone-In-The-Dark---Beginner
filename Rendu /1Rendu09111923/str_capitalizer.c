#include <unistd.h>

void    str_capitalizer(char *str)
{
    while(*str)
    {
        while(*str && (*str == ' ' || *str == '\t'))
        {
            write (1, str, 1);
            ++str;
        }
        if (*str)
        {
            if(*str >= 'a' && *str <= 'z')
                *str = *str - ('a' - 'A');
            write (1, str, 1);
            ++str;
        }
        while (*str && *str != ' ' && *str != '\t')
        {
            if (*str >= 'A' && *str <= 'Z')
                *str = *str + ('a' - 'A');
            write (1, str, 1);
            ++str;
        }
    }
    write (1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        write (1, "\n", 1);
    else
    {
        int i;
        i = 1;
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            ++i;
        }
    }
    return (0);
    
}

//Assignment name  : str_capitalizer
//Expected files   : str_capitalizer.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes one or several strings and, for each argument,
//capitalizes the first character of each word (If it's a letter, obviously),
//puts the rest in lowercase, and displays the result on the standard output,
//followed by a \n.
//
//A "word" is defined as a part of a string delimited either by spaces/tabs, or
//by the start/end of the string. If a word only has one letter, it must be
//capitalized.
//
//If there are no arguments, the progam must display \n.
//
//Example:
//
//$> ./str_capitalizer | cat -e
//$
//$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
//A First Little Test$
//$> ./str_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
//Second Test A Little Bit   Moar Complex$
//   But... This Is Not That Complex$
//     Okay, This Is The Last 1239809147801 But Not    The Least    T$
//$>

