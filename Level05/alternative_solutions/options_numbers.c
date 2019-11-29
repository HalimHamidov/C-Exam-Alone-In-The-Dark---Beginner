#include <unistd.h>

void    ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

int        options(char *str, int flags)
{
    int i = 1;
    int bitflag;
    
    while (str[i])
    {
        if (str[i] < 'a' || str[i] > 'z')
            return (-1);
        else if (str[i] == 'h')
            return (-2);
        bitflag = 1 << (str[i] - 'a');
        flags = flags | bitflag;
        ++i;
    }
    return (flags);
}

int        main(int ac, char **av)
{
    if (ac == 1)
    {
        write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
        return (0);
    }
    
    int i = 1;
    int flags = 0;
    
    while (i < ac)
    {
        if (av[i][0] == '-' && (flags = options(av[i], flags)) < 0)
        {
            if (flags == -1)
                write(1, "Invalid Option\n", 15);
            else if (flags == -2)
                write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
            return (0);
        }
        ++i;
    }
    
    ft_putnbr(flags);
    write(1, "\n", 1);
    return (0);
}
//
//Assignment name  : options
//Expected files   : *.c *.h
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that takes an undefined number of arguments which could be
//considered as options and writes on standard output a representation of those
//options as groups of bytes followed by a newline.
//
//An option is an argument that begins by a '-' and have multiple characters
//which could be : abcdefghijklmnopqrstuvwxyz
//
//All options are stocked in a single int and each options represents a bit of that
//int, and should be stocked like this :
//
//00000000 00000000 00000000 00000000
//******zy xwvutsrq ponmlkji hgfedcba
//
//Launch the program without arguments or with the '-h' flag activated must print
//an usage on the standard output, as shown in the following examples.
//
//A wrong option must print "Invalid Option" followd by a newline.
//
//Examples :
//$>./options
//options: abcdefghijklmnopqrstuvwxyz
//$>./options -abc -ijk
//00000000 00000000 00000111 00000111
//$>./options -z
//00000010 00000000 00000000 00000000
//$>./options -abc -hijk
//options: abcdefghijklmnopqrstuvwxyz
//$>./options -%
//Invalid Option

