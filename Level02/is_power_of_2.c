#include <stdio.h>
#include <stdlib.h>

int        is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    while (n % 2 == 0)
        n = n / 2;      // return(n = n / 2) is wrong
    if (n == 1)
        return (1);
    else
        return (0);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("Is %s power of 2? ", av[1]);
        is_power_of_2(atoi(av[1])) ? printf("Yes\n") : printf("No\n");
    }
    return (0);
}

/*
il-h5% ./is_power_of_2 8
Is 8 power of 2? Yes
il-h5% ./is_power_of_2 9
Is 9 power of 2? No
il-h5% ./is_power_of_2 339
Is 339 power of 2? No
il-h5% ./is_power_of_2 3456
Is 3456 power of 2? No
il-h5% ./is_power_of_2 3467
Is 3467 power of 2? No
il-h5% ./is_power_of_2 3468
Is 3468 power of 2? No
il-h5% ./is_power_of_2 12
Is 12 power of 2? No
*/
//
//Assignment name  : is_power_of_2
//Expected files   : is_power_of_2.c
//Allowed functions: None
//--------------------------------------------------------------------------------
//
//Write a function that determines if a given number is a power of 2.
//
//This function returns 1 if the given number is a power of 2, otherwise it returns 0.
//
//Your function must be declared as follows:
//
//int        is_power_of_2(unsigned int n);

