#include <unistd.h>
#include <stdio.h>

 unsigned char reverse_bits(unsigned char octet)
 {
     int i;
     int r;

     i = 0;
     r = 0;
     while (i < 8)
     {
         r |= (((octet >> i) & 1)) << (7 - i);
         i++;
     }
     return (r);
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
    unsigned char c;
    unsigned char octet = 8;
 
    c = reverse_bits(octet);
    printf("%c%c%d\n%d\n", print_bits(octet), print_bits(c), octet, reverse_bits(octet));
    return 0;
}

/*
il-h5% gcc reverse_bits.c
il-h5% ./a.out
00000011
11000000
3
192
*/

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

//unsigned char reverse_bits(unsigned char octet)
//{
//    return (((octet >> 0) & 1) << 7) | \
//    (((octet >> 1) & 1) << 6) | \
//    (((octet >> 2) & 1) << 5) | \
//    (((octet >> 3) & 1) << 4) | \
//    (((octet >> 4) & 1) << 3) | \
//    (((octet >> 5) & 1) << 2) | \
//    (((octet >> 6) & 1) << 1) | \
//    (((octet >> 7) & 1) << 0);
//}
//
//Assignment name  : reverse_bits
//Expected files   : reverse_bits.c
//Allowed functions:
//--------------------------------------------------------------------------------
//
//Write a function that takes a byte, reverses it, bit by bit (like the
//                                                             example) and returns the result.
//
//Your function must be declared as follows:
//
//unsigned char    reverse_bits(unsigned char octet);
//
//Example:
//
//1 byte
//_____________
//0100  0001
//||
//\/
//1000  0010

