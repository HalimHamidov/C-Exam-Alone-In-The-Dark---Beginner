#include <unistd.h>
#include <stdio.h>


char    *ft_strrev(char *str)
{
    int        length;
    int        j;
    int        i;
    char    temp;
    
    length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    i = 0;
    j = length - 1;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}

int main()
{
    
    char str[] = "hellodfgdasdsdfsdfasdfasfdffg";
    
    printf("%s", ft_strrev(str));
    
    return (0);
}
