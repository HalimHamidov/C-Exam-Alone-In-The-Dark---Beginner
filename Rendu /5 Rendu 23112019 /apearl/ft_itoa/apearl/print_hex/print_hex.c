#include <unistd.h>

int     ft_atoi(char *str);

void    ft_print_hex(int x);

int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_print_hex(ft_atoi(argv[1]));
        write (1, "\n", 1);
    }
    else
        write (1, "\n", 1);
    return (0);
}

void    ft_print_hex(int x)
{
    char *str;
    
    str = "0123456789abcdef";
    
    if (x >= 16)
        ft_print_hex(x / 16);
    write (1, &str[x % 16], 1);
}

int     ft_atoi(char *str)
{
    int i;
    int r;
    
    i = 0;
    r = 0;
    
    while (*str == ' ' || *str == '\n' || *str == '\t' \
           || *str == '\v' ||*str == '\r' ||*str == '\f')
        str++;
    while (*str != '\0' && *str >= '0' && *str <= '9')
    {
        r = r * 10 + *str - '0';
        str++;
    }
    return (r);
}
