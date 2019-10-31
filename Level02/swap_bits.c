#include <stdio.h>
#include <unistd.h>

unsigned char    swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

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

int main()
{
    char a = 'a';
    print_bits(a);
    a = swap_bits(a);
    print_bits(a);
    return 0;
}
/*
il-h5% gcc swap_bits.c  // char a = 'a';
il-h5% ./a.out
01100001
00010110
il-h5% gcc swap_bits.c    // char a = 8;
il-h5% ./a.out
00001000
10000000
il-h5%
*/


// void print_bits(char a)
// {
//     int i;
//     i = 7;
//     while (i >= 0)
//     {
//         printf("%d", (1 & (a >> i)));
//         i--;
//     }
//       printf("\n");
// }

// void printb(char a) {
//     int i;
//     for( i = 7; i >= 0; i--)
//         printf("%d", (1 &  (a >> i)));
//     printf("\n");
// }
