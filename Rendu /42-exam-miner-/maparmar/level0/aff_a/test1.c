#include <unistd.h>

int main (int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 2)
        write(1, "a\n", 1);
    else
    {
        while (argv[1][i])
        {
            if (argv[1][i] != 'a')
                i++;
            else
            {
                write(1, "a", 1);
                break ;
            }
        }
        write(1, "\n", 1);
    }
    return (0);
}