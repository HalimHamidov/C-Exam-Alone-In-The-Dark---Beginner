#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    i = 0;
    char c;
    if (argc != 2)
    {
        write(1, "\n", 1);
    }
    if (argc == 2)
    {
        while (argv[1][i])
        {
            c = argv[1][i];
            if (c >= 'a' && c <= 'y')
                c++;
            if (c >= 'A' && c <= 'Y')
                c++;
            if (c == 'z' && c == 'Z')
                c = c - 25;
            write (1, &c, 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}