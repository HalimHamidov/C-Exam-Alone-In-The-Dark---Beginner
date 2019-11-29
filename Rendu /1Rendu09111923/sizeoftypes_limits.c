#include <stdio.h>
#include <limits.h> /* Test integer limits in <limits.h> header */
int main() {
/* Print Size of Fundamental Types (SizeofTypes).*/
   printf("sizeof(char) is %lu bytes.\n", sizeof(char));
   printf("sizeof(short) is %lu bytes.\n", sizeof(short));
   printf("sizeof(int) is %lu bytes.\n", sizeof(int));
   printf("sizeof(long) is %lu bytes.\n", sizeof(long));
   printf("sizeof(long long) is %lu bytes.\n", sizeof(long long));
   printf("sizeof(float) is %lu bytes.\n", sizeof(float));
   printf("sizeof(double) is %lu bytes.\n", sizeof(double));
   printf("sizeof(long double) is %lu bytes.\n", sizeof(long double));
// integer limits
   printf("int max = %d\n", INT_MAX);
   printf("int min = %d\n", INT_MIN);
   printf("unsigned int max = %u\n", UINT_MAX);

   printf("long max = %ld\n", LONG_MAX);
   printf("long min = %ld\n", LONG_MIN);
   printf("unsigned long max = %lu\n", ULONG_MAX);

   printf("long long max = %lld\n", LLONG_MAX);
   printf("long long min = %lld\n", LLONG_MIN);
   printf("unsigned long long max = %llu\n", ULLONG_MAX);

   printf("Bits in char = %d\n", CHAR_BIT);
   printf("char max = %d\n", CHAR_MAX);
   printf("char min = %d\n", CHAR_MIN);
   printf("signed char max = %d\n", SCHAR_MAX);
   printf("signed char min = %d\n", SCHAR_MIN);
   printf("unsigned char max = %u\n", UCHAR_MAX);
   return 0;
}
//sizeof(char) is 1 bytes.
//sizeof(short) is 2 bytes.
//sizeof(int) is 4 bytes.
//sizeof(long) is 8 bytes.
//sizeof(long long) is 8 bytes.
//sizeof(float) is 4 bytes.
//sizeof(double) is 8 bytes.
//sizeof(long double) is 16 bytes.
//int max = 2147483647
//int min = -2147483648
//unsigned int max = 4294967295
//long max = 9223372036854775807
//long min = -9223372036854775808
//unsigned long max = 18446744073709551615
//long long max = 9223372036854775807
//long long min = -9223372036854775808
//unsigned long long max = 18446744073709551615
//Bits in char = 8
//char max = 127
//char min = -128
//signed char max = 127
//signed char min = -128
//unsigned char max = 255
//https://www.ntu.edu.sg/home/ehchua/programming/cpp/c1_Basics.html
