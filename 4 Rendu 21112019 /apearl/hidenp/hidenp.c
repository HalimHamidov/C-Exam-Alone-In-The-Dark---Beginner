#include <unistd.h>

int ft_hidenp(char *s1, char *s2);

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        if (ft_hidenp(argv[1], argv[2]))
        {
            write (1, "1\n", 2);
        }
        else
        {
            write (1, "0\n", 2);
        }
    }
    else
        write (1, "\n", 1);
    return (0);
}


int ft_hidenp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (*s2 == 0)
        s2++;
    while (*s1 == 0)
        s1++;
    while (*s2)
    {
        
        if (s2[*s1++])
        {
            if (*s2 != *s1)
                return (1);
            else
                return (0);
        }
        
    }
    return (0);
}
