#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int do_op(int a, int b, char c)
{
    if (c == '+')
        return (a + b);
    if (c == '-')
        return (a - b);
    if (c == '*')
        return (a * b);
    if (c == '/')
        return (a / b);
    if (c == '%')
        return (a % b);
    return (0);
}

int main (int argc, char **argv)
{
    if (argc != 4)
    {
        write (1, "\n", 1);
    }
    if (argc == 4)
    {
        printf("%d\n", do_op(atoi(argv[1]), atoi(argv[3]),argv[2][0]));
    }
    return (0);
}
