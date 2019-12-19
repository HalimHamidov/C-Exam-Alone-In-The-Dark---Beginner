#include <unistd.h>

#define MATCH(a,b) ((a == ')' && b == '(') || (a == ']' && b == '[') || (a == '}' && b == '{'))

int main(int argc, char **argv)
{
    int i = 1;
    if (argc < 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    while (i < argc)
    {
        if (br(argv[i]) == -1)
            write (1, "Error\n", 6);
        else
            write (1, "OK\n", 3);
        i++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
int br(char *str)
{
    int i = 0;
    int stack[ft_strlen(str)];
    while (*str)
    {
        if (*str == '(' || *str == '[' || *str == '{')
            stack[++i] = *str;
        else if (*str == ')' || *str == ']' || *str == '}')
        {
            if (MATCH(*str, stack[i]) == 0)
                return (-1);
            --i;
        }
        str++;
    }
    if (i != 0)
        return (-1);
    return (0);
}
