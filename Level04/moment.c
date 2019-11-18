/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:29:25 by apearl            #+#    #+#             */
/*   Updated: 2019/11/15 21:38:04 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int    ft_nbrlen(long c, int len)
{
    int        base;
    
    base = 10;
    while (c > 0)
    {
        c /= base;
        len++;
    }
    return (len);
}

size_t    ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char        *ft_itoa(int n)
{
    int        len;
    long    nb;
    char    *res;
    char    *str;
    
    str = "0123456789";
    len = n < 0 ? 1 : 0;
    nb = n < 0 ? -(long)n : n;
    len = ft_nbrlen(nb, len);
    len = (n == 0) ? 1 : len;
    if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    if (n == 0)
        res[0] = '0';
    res[len] = '\0';
    while (nb > 0)
    {
        res[--len] = str[nb % 10];
        nb /= 10;
    }
    if (n < 0)
        res[0] = '-';
    return (res);
}

char    *ft_strcpy(char *dst, const char *src)
{
    size_t i;
    
    i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
char    *moment_months(unsigned int duration)
{
    int     len;
    char    *str;
    char    *ptr_str;
    char    *numb;
    
    duration /= 2592000;
    numb = ft_itoa(duration);
    len += ft_strlen(numb);
    len += ft_strlen(" month ago.");
    if (duration != 1)
        len += 1;
    str = malloc(len * sizeof(char));
    ptr_str = str;
    ft_strcpy(str, numb);
    str += ft_strlen(numb);
    if (duration != 1)
        ft_strcpy(str, " months ago.");
    else
        ft_strcpy(str, " month ago.");
    free(numb);
    return (ptr_str);
}
char    *moment_days(unsigned int duration)
{
    int     len;
    char    *str;
    char    *ptr_str;
    char    *numb;
    
    duration /= 86400;
    numb = ft_itoa(duration);
    len += ft_strlen(numb);
    len += ft_strlen(" day ago.");
    if (duration != 1)
        len += 1;
    str = malloc(len * sizeof(char));
    ptr_str = str;
    ft_strcpy(str, numb);
    str += ft_strlen(numb);
    if (duration != 1)
        ft_strcpy(str, " days ago.");
    else
        ft_strcpy(str, " day ago.");
    free(numb);
    return (ptr_str);
}

char    *moment_hours(unsigned int duration)
{
    int     len;
    char    *str;
    char    *ptr_str;
    char    *numb;
    
    duration /= 3600;
    numb = ft_itoa(duration);
    len += ft_strlen(numb);
    len += ft_strlen(" hour ago.");
    if (duration != 1)
        len += 1;
    str = malloc(len * sizeof(char));
    ptr_str = str;
    ft_strcpy(str, numb);
    str += ft_strlen(numb);
    if (duration != 1)
        ft_strcpy(str, " hours ago.");
    else
        ft_strcpy(str, " hour ago.");
    free(numb);
    return (ptr_str);
}

char    *moment_minutes(unsigned int duration)
{
    int     len;
    char    *str;
    char    *ptr_str;
    char    *numb;
    
    duration /= 60;
    numb = ft_itoa(duration);
    len += ft_strlen(" minute ago.");
    len += 12;
    if (duration != 1)
        len += 1;
    str = malloc(len * sizeof(char));
    ptr_str = str;
    ft_strcpy(str, numb);
    str += ft_strlen(numb);
    if (duration != 1)
        ft_strcpy(str, " minutes ago.");
    else
        ft_strcpy(str, " minute ago.");
    free(numb);
    return (ptr_str);
}

char    *moment_seconds(unsigned int duration)
{
    int     len;
    char    *str;
    char    *ptr_str;
    char    *numb;
    
    numb = ft_itoa(duration);
    len += ft_strlen(numb);
    len += ft_strlen(" second ago.");
    if (duration != 1)
        len += 1;
    str = malloc(len * sizeof(char));
    ptr_str = str;
    ft_strcpy(str, numb);
    str += ft_strlen(numb);
    if (duration != 1)
        ft_strcpy(str, " seconds ago.");
    else
        ft_strcpy(str, " second ago.");
    free(numb);
    return (ptr_str);
}

char    *moment(unsigned int duration)
{
    if (duration < 60)
        return (moment_seconds(duration));
    if (duration < 3600)
        return (moment_minutes(duration));
    if (duration < 86400)
        return (moment_hours(duration));
    if (duration < 2592000)
        return (moment_days(duration));
    if (duration < 31104000)
        return (moment_months(duration));
    return (NULL);
}

int     main(void)
{
    printf("%s\n", moment(0));
    printf("%s\n", moment(1));
    printf("%s\n", moment(30));
    printf("%s\n", moment(65));
    printf("%s\n", moment(120));
    printf("%s\n", moment(2400));
    printf("%s\n", moment(3735));
    printf("\n");
    printf("%s\n", moment(50));
    printf("%s\n", moment(10));
    printf("%s\n", moment(0));
    printf("%s\n", moment(1));
    printf("%s\n", moment(65));
    printf("%s\n", moment(120));
    printf("%s\n", moment(2400));
    printf("%s\n", moment(3599));
    printf("%s\n", moment(3600));
    printf("%s\n", moment(36000));
    printf("%s\n", moment(12345));
    printf("%s\n", moment(86399));
    printf("%s\n", moment(86400));
    printf("%s\n", moment(100000));
    printf("%s\n", moment(123450));
    printf("%s\n", moment(863990));
    printf("%s\n", moment(2593000));
    printf("%s\n", moment(3000000));
    printf("%s\n", moment(5000000));
    printf("%s\n", moment(20000000));
    printf("%s\n", moment(33100000));
    
}

//Assignment name  : moment
//Expected files   : moment.c
//Allowed functions: malloc, free
//--------------------------------------------------------------------------------
//
//Create a function that takes a duration in seconds as parameter and returns a
//string with the number of seconds, minutes, hours, days or months elapsed.
//This function supposes that months are 30-days long and ignores leap years.
//
//The format of this string will be :
//
//xxx {second(s)|minute(s)|hour(s)|day(s)|month(s)} ago.
//
//Your function should return the lowest possible value (as you can see below
//                                                       in the examples).
//
//The prototype of this function will be :
//
//char    *moment(unsigned int duration)
//
//Examples:
//
//moment(0)       => 0 seconds ago.
//moment(1)       => 1 second ago.
//moment(30)      => 30 seconds ago.
//moment(65)      => 1 minute ago.
//moment(120)     => 2 minutes ago.
//moment(2400)    => 40 minutes ago.
//moment(3735)    => 1 hour ago.
