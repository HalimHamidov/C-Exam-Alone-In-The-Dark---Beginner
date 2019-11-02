#include <unistd.h>

int main(void)
{
    char a;
    char b;
    
    a = 'z';
    b = 'Y';
    
    while (b >= 'A')
    {
        write (1, &a, 1);
        write (1, &b, 1);
        b -= 2;
        a -= 2;
    }
    write (1, "\n", 1);
    return (0);
}
//Assignment name  : maff_revalpha
//Expected files   : maff_revalpha.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that displays the alphabet in reverse, with even letters in
//uppercase, and odd letters in lowercase, followed by a newline.
//
//Example:
//
//$> ./maff_revalpha | cat -e
//zYxWvUtSrQpOnMlKjIhGfEdCbA$
//

