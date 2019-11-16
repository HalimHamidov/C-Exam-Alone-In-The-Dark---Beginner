#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    i = 0;
    char c;
    char d;
    if (argc != 2)
    {
        write(1, "\n", 1);
    }
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            c = argv[1][i];
            if (c >= 'A' && c <= 'Z')
            {
                d = c - 'A' + 'a';
                write (1, &d, 1);
            }
            else if (c >= 'a' && c <= 'z')
            {
                d = c - 'a' + 'A';
                write (1, &d, 1);
            }
            else 
            {
                write (1, &c, 1);
            }
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}

