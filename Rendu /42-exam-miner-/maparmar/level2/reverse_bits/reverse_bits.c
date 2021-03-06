#include <unistd.h>
#include <stdio.h>

// unsigned char reverse_bits(unsigned char octet)
// {
//     int i;
//     int r;

//     i = 0;
//     r = 0;
//     while (i < 8)
//     {
//         r |= (((octet >> i) & 1)) << (7 - i);
//         i++;
//     }
//     return (r);
// }
unsigned char reverse_bits(unsigned char octet)
{
    return (((octet >> 0) & 1) << 7) | \
           (((octet >> 1) & 1) << 6) | \
           (((octet >> 2) & 1) << 5) | \
           (((octet >> 3) & 1) << 4) | \
           (((octet >> 4) & 1) << 3) | \
           (((octet >> 5) & 1) << 2) | \
           (((octet >> 6) & 1) << 1) | \
           (((octet >> 7) & 1) << 0); 
}
unsigned char	print_bits(unsigned char octet)
{
    int i = 128;
    while (i)
    {
        (octet & i) ? write(1, "1", 1) : write(1, "0", 1);
        i = i / 2;
    }
    write(1, "\n", 1);
    return (0);
}

int main()
{
    unsigned char c,d;
    unsigned char octet = 3;
    unsigned char octet2 = 'a';
    c = reverse_bits(octet);
    printf("%c %c %d\n %d\n ", print_bits(octet), print_bits(c), octet, reverse_bits(octet));
    return 0;
}
//int	main(void)
//{
//    unsigned char c;
//
//    c = '.';
//    write(1, &c, 1);
//    write(1, "\n", 1);
//    c = reverse_bits(c);
//    write(1, &c, 1);
//    write(1, "\n", 1);
////    c = reverse_bits2(c);
////    write(1, &c, 1);
////    write(1, "\n", 1);
////    c = reverse_bits3(c);
////    write(1, &c, 1);
////    write(1, "\n", 1);
//    return (0);
//}

