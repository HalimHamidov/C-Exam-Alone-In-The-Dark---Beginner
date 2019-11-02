#include <unistd.h>

int main(void)
{
    write (1,"z\n", 2);
    return (0);
}

//Assignment name  : only_z
//Expected files   : only_z.c
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program that displays a 'z' character on the standard output.


