#include <stdio.h>
#include <unistd.h>

void print_bits(char a)
{
    int i;
    i = 7;
    while (i >= 0)
    {
        char d;
        d = (1 & (a >> i));
        write(1, &d, 1);
    
    }
      write(1, "\n", 1);
}
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
unsigned char	swap_bits(unsigned char octet)
{
    octet = (octet >> 4 | octet << 4);
    return (octet);
}


int main()
{
    char a = 10;
    print_bits(a);
    a = swap_bits(a);
    print_bits(a);
    return 0;
}