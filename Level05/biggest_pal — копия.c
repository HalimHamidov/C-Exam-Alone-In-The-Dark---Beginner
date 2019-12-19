#include <unsitd.h>

void print_pal(char *str, int l, int h);
void biggest_pal(char *str);

int main(int argc, char **argv)
{
    if (argc == 2)
        biggest_pal(argv[1]);
    write (1, "\n", 1);
    return (0);
}

void print_pal(char *str, int l, int h)
{
    while (l <= h)
        write (1, &str[l++],1);
}

void biggest_pal(char *str)
{
    int i = 1;
    int len = 0;
    int l,
    int h,
    int ml = 1,
    int s;
    while (str[len])
        len++;
    while (++i < len)
    {
        l = h - 1;
        h = i;
        while (l >= 0 && h < len && str[l] == str[h])
        {
            if (h - l + 1 >= ml)
            {
                s = l;
                ml = h - l + 1;
            }
            --l;
            ++h;
        }
        l = h - 1;
        h = i + 1;
        while (l >= 0 && h < len && str[l] == str[h])
        {
            if (h - l + 1 >= ml)
            {
                s = l;
                ml = h - l + 1;
            }
            --l;
            ++h;
        }
    }
    print_pal(str, s, s+ml -1);
}
