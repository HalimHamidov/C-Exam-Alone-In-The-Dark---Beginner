#include <stdlib.h>

size_t    ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

int ft_nbrlen(long nbr, int len)
{
    while (nbr > 0)
    {
        nbr = nbr/10;
        len++;
    }
    return (len);
}

char *ft_itoa(int nb)
{
    int nbr;
    char *res;
    int len;
    char *str;
    
    str = "0123456789";
    len = nb < 0 ? 1 : 0;
    nbr = nb < 0 ? -(long)nb : nb;
    len = ft_nbrlen(nbr, len);
    len = (nb == 0) ? 1 : len;
    if (!(res = (char *)malloc(sizeof(char)*(len+1))))
        return (NULL);
    if (nb < 0)
        res[0] = '-';
    if (nb == 0)
        res[0] = '0';
    res[len] = '\0';
    while (nbr > 0)
    {
        res[--len] = str[nbr % 10];
        nbr = nbr/10;
    }
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
    
    len = 0;
    duration /= 60;
    numb = ft_itoa(duration);
    len += ft_strlen(numb);
    len += ft_strlen(" minute ago.");
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

   len = 0; 
    numb = ft_itoa(duration);
    len += ft_strlen(numb);
    len += ft_strlen(" second ago.");
    if (duration != 1)
        len += 1;
    str = malloc(len * sizeof(char));
    printf();
    ptr_str = str;
    ft_strcpy(str, numb);
    str = str + ft_strlen(numb);//ft_strlen(numb);
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
