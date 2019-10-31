#include <unistd.h>
#include <stdio.h>

void    ft_putnbr(int nbr)
{
    char    c;
    
    if (nbr < 0)
    {
        nbr = -nbr;
        write(1, "-", 1);
    }
    if (nbr < 10)
    {
        c = nbr + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}

void print_bits(char a)
{
    int i;
    i = 7;
    while (i >= 0)
    {
        ft_putnbr(1 & (a >> i));
        i--;
    }
    write(1, "\n", 1);
}
int main (void)
{
    int i;
    i = 0;
    char c;
    c = '0';

    while (i <= 10 && c <= '9')
    {
        write(1, &c, 1);
        write(1, " ", 1);
        print_bits(i);
        write(1, "\n", 1);
        i++;
        c++;

    }
    return (0);
}

/*
il-h5% gcc print_bits.c
il-h5% ./a.out
0 00000000

1 00000001

2 00000010

3 00000011

4 00000100

5 00000101

6 00000110

7 00000111

8 00001000

9 00001001
 */


//void    print_bits(unsigned char octet)
//{
//    int i = 128;
//    while (i)
//    {
//        (octet & i) ? write(1, "1", 1) : write(1, "0", 1);
//        i = i / 2;
//    }
//}
//void    print_bits(unsigned n)
//{
//    unsigned i;
//    i = 1 << 31;
//
//    while (i)
//    {
//        (n & i) ? write(1, "1", 1) : write(1, "0", 1);
//        i = i / 2;
//    }
//}
