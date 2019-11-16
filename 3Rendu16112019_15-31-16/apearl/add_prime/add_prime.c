#include <unistd.h>
#include <stdlib.h>

void ft_putnbr(int n)
{
    char c;
    
    if (n < 0)
    {
        n = -n;
        write (1, "-", 1);
    }
    else if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else if (n < 10)
    {
        c = n + '0';
        write (1, &c, 1);
    }

}

unsigned int add_prime_sum(unsigned int n)
{
//    unsigned int i = 1;
//    int tmp = 2;
//    int tmp2;
    int sum = 0;
//
//    while (i < n)
//    {
//        if (n % 2)
//           sum = sum +tmp + n;
//    }

    if (n % 2)
    {
       while (n > 1)
       {
           sum = 2+sum + n;
            n--;
       }

    }

//    if (n == 3)
//        sum = 2+3; 5
//    if (n == 5)
//        sum = 2+3+5; 10
//    if (n == 7)
//        sum = 2+3+5+7; 17
//    if (n == 11)
//        sum = 2+3+5+7+11; 28
//    if (n == 13)
//        sum = 2+3+5+7+11+13; 41
//    if (n == 17)
//        sum = 2+3+5+7+11+13+17;58
//    if (n == 19)
//        sum = 2+3+5+7+11+13+17+19;
    ft_putnbr(sum);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2 || argc < 0)
    {
        write(1, "0\n", 2);
    }
    else
    {
        add_prime_sum(atoi(argv[1]));
        write (1, "\n", 1);
    }
    return (0);
}
