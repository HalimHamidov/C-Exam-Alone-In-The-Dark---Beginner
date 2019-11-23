// #include <stdio.h>
// #include <stdlib.h>

// int fprime(unsigned int n);
// int main(int argc, char **argv)
// {
//     //int i = 1; // 0 mistake

//     if (argc == 2)
//         fprime(atoi(argv[1]));
//     printf("\n");// 0 mistake
//     return (0);//1 mistake
// }

// int fprime(unsigned int n)
// {
//     int i;
//     i = 1; // 2 mistake i =1 not 0
//     if (n == 1)
//         printf("1"); // 3 mistake return(1)
//     while (n >= ++i) // 4 mistake (++i > 0)
//     {
//         if (n % i == 0) // 5 mistake (n>0)  6/th mistake n%2==0 is wrong
//         {
//             printf("%d", i);// i not n
//             if (n == i)// 8th mistake not (n%2 == 0)
//                 break;
//             printf("*");
//             // if (n % 2 == 0)
//             //     break ;
//             n = n / i; // 9th not n/2 but n = n/i
//             i = 1;
//         }
//     }
//     return (0);
// }

// Assignment name  : fprime
// Expected files   : fprime.c
// Allowed functions: printf, atoi
// --------------------------------------------------------------------------------

// Write a program that takes a positive int and displays its prime factors on the
// standard output, followed by a newline.

// Factors must be displayed in ascending order and separated by '*', so that
// the expression in the output gives the right result.

// If the number of parameters is not 1, simply display a newline.

// The input, when there's one, will be valid.

// Examples:

// $> ./fprime 225225 | cat -e
// 3*3*5*5*7*11*13$
// $> ./fprime 8333325 | cat -e
// 3*3*5*5*7*11*13*37$
// $> ./fprime 9539 | cat -e
// 9539$
// $> ./fprime 804577 | cat -e
// 804577$
// $> ./fprime 42 | cat -e
// 2*3*7$
// $> ./fprime 1 | cat -e
// 1$
// $> ./fprime | cat -e
// $
// $> ./fprime 42 21 | cat -e
// $

#include <stdlib.h>
#include <stdio.h>

void fprime(unsigned int n);
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        fprime(atoi(argv[1]));
    }
    printf("\n");
    return (0);
}
void fprime(unsigned int n)
{
    int i = 1;
    if (n == 1)
        printf("1");
    while (n >= ++i)
    {
        if (n % i == 0)
        {
            printf("%d", i);
            if (n == i)
                break ;
            printf("*");
            n = n / i;
            i = 1;
        }
    }
}
