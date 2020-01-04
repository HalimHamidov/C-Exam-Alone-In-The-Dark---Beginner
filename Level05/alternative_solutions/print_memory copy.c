#include <unistd.h>

void    ft_print_hex(unsigned char c)
{
    char *radix;
    
    radix = "0123456789abcdef";
    write(1, &radix[c / 16], 1);
    write(1, &radix[c % 16], 1);
}

void    ft_print_char(unsigned char c)
{
    if (c >= ' ' && c <= '~')
        write(1, &c, 1);
    else
        write(1, ".", 1);
}
void    print_memory(const void *addr, size_t size)
{
    size_t i = 0;
    size_t j = 0;
    unsigned char const *p = addr;
    while (i < size)
    {
        j = 0;
        while (j < 16 && i+j < size)
        {
            ft_print_hex(*(p+i+j));
            if (j%2)
                write (1, " ", 1);
            j++;
        }
        while (j < 16)
        {
            write (1, "  ", 2);
            if (j%2)
                write (1, " ", 1);
            j++;
        }
        j = 0;
        while (j < 16 && i+j < size)
        {
            ft_print_char(*(p+i+j));
            j++;
        }
        write (1, "\n", 1);
        i += 16;
    }
}
//void    print_memory(const void *addr, size_t size)
//{
//    size_t i;
//    size_t j;
//    unsigned char *ptr;
//
//    i = 0;
//    j = 0;
//    ptr = (unsigned char*)addr;
//    while (i < size)
//    {
//        j = 0;
//        while (j < 16 && i + j < size)
//        {
//            ft_print_hex(ptr[i + j]);
//            if (j % 2)
//                write(1, " ", 1);
//            j++;
//        }
//        while (j < 16)
//        {
//            write(1, "  ", 2);
//            if (j % 2)
//                write(1, " ", 1);
//            j++;
//        }
//        j = 0;
//        while (j < 16 && i + j < size)
//        {
//            ft_print_char(ptr[i + j]);
//            j++;
//        }
//        write(1, "\n", 1);
//        i += 16;
//    }
//}


#include <string.h>

void    print_memory(const void *addr, size_t size);

int    main(void)
{
    int    tab[10] = {0, 23, 150, 255,
        12, 16,  21, 42};
    
    print_memory(tab, sizeof(tab));
    return (0);
    
}


//#IMP Notes: 
//The main concept of print memory is to print each byte at a time because memory in real is always store in the cpu by the token of bytes.

//Assignment name  : print_memory
//Expected files   : print_memory.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a function that takes (const void *addr, size_t size), and displays the
//memory as in the example.
//
//Your function must be declared as follows:
//
//void    print_memory(const void *addr, size_t size);
//
//---------
//$> cat main.c
//void    print_memory(const void *addr, size_t size);
//
//int    main(void)
//{
//    int    tab[10] = {0, 23, 150, 255,
//        12, 16,  21, 42};
//    
//    print_memory(tab, sizeof(tab));
//    return (0);
//}
//$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e
//0000 0000 1700 0000 9600 0000 ff00 0000 ................$
//0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$
//0000 0000 0000 0000                     ........$

