#include <unistd.h>

void    print_hex(int x)
{
    char *base;
    
    base = "0123456789abcdef";
    write(1, &base[x / 16], 1);
    write(1, &base[x % 16], 1);
}

void    print_char(char c)
{
    if (c >= 32 && c <= 126)
        write (1, &c, 1);
    else
        write (1, ".", 1);
}

void    print_memory(const void *addr, size_t size)
{
    size_t i;
    size_t j;
    unsigned char const *p = addr;
    
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < 16 && (i + j) < size)
        {
            print_hex(*(p + i + j));
            if (j % 2)
                write (1, " ", 1);
            j++;
        }
        while (j < 16)
        {
            write (1, "  ", 2);
            if (j % 2)
                write (1, " ", 1);
            j++;
        }
        j = 0;
        while (j < 16 && (i + j) < size)
        {
            print_char(*(p + i + j));
            j++;
        }
        write (1, "\n", 1);
        i += 16;
    }
}
