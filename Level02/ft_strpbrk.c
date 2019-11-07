int        find_char(const char c, const char *str)
{
    while (*str)
    {
        if (*str == c)
            return (1);
        ++str;
    }
    return (0);
}

char    *ft_strpbrk(const char *s1, const char *s2)
{
    while (*s1)
    {
        if (find_char(*s1, s2) == 1)
            return ((char *)s1);
        ++s1;
    }
    return (0);
}

//--------------------------------------------------------------
// #include <stdio.h>
// #include <string.h>
//
// int        main(void)
// {
//     printf("ft: %s; real: %s\n", \
//         ft_strpbrk("This is a string to search in", "qxd"), \
//         strpbrk("This is a string to search in", "qxd")
//         );
//
//     printf("ft: %s; real: %s\n", \
//         ft_strpbrk("This is a string to search in", "sh"), \
//         strpbrk("This is a string to search in", "sh")
//         );
// }
//--------------------------------------------------------------
#include <string.h>
#include <stdio.h>

int main( void )
{
    char string[100] = "The 3 men and 2 boys ate 5 pigs\n";
    char *result = NULL;
    
    // Return pointer to first digit in "string".
    printf( "1: %s\n", string );
    result = strpbrk( string, "0123456789" );
    printf( "2: %s\n", result++ );
    result = strpbrk( result, "0123456789" );
    printf( "3: %s\n", result++ );
    result = strpbrk( result, "0123456789" );
    printf( "4: %s\n", result );
}

//Assignment name    : ft_strpbrk
//Expected files    : ft_strpbrk.c
//Allowed functions: None
//---------------------------------------------------------------
//
//Reproduce exactly the behavior of the function strpbrk
//(man strpbrk).
//
//The function should be prototyped as follows:
//
//char    *ft_strpbrk(const char *s1, const char *s2);
//https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/reference/strpbrk-wcspbrk-mbspbrk-mbspbrk-l?view=vs-2019

