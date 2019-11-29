/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:13:46 by exam              #+#    #+#             */
/*   Updated: 2019/03/19 09:23:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

//void    print_bits(unsigned char octet)
//{
//    int i = 128;
//    while (i)
//    {
//        (octet & i) ? write(1, "1", 1) : write(1, "0", 1);
//        i = i / 2;
//    }
//}
//void    print_bits(unsigned n)
//{
//    unsigned i;
//    i = 1 << 31;
//
//    while (i)
//    {
//        (n & i) ? write(1, "1", 1) : write(1, "0", 1);
//        i = i / 2;
//    }
//}
void    ft_putnbr(int nbr)
{
    char    c;
    
    if (nbr < 0)
    {
        nbr = -nbr;
        write(1, "-", 1);
    }
    if (nbr < 10)
    {
        c = nbr + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}

void print_bits(char a)
{
    int i;
    i = 7;
    while (i >= 0)
    {
        ft_putnbr(1 & (a >> i));
        i--;
    }
    write(1, "\n", 1);
}
int main (void)
{
    int i;
    i = 0;
    char c;
    c = '0';

    while (i <= 10 && c <= '9')
    {
        write(1, &c, 1);
        write(1, " ", 1);
        print_bits(i);
        write(1, "\n", 1);
        i++;
        c++;

    }
    return (0);
}
