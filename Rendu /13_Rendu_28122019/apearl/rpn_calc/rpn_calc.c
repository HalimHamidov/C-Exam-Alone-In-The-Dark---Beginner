#include <stdlib.h>
#include <stdio.h>

int is_number(char *c);
int is_operator(char *c);
int rpn_calc(char *str, int *result);

int main(int argc, char **argv)
{
    int result = 0;
    if (argc != 2)  // here was a mistake i wrote argc < 2 , If the string isn't valid or there isn't exactly one argument, you must print
        //"Error"
        printf("Error\n");
    else
    {
        if (rpn_calc(argv[1], &result) == -1)
            printf("Error\n");
        else
            printf("%d\n", result);
    }
    return (0);
}

int is_number(char *c)
{
    if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%')
    {
        if (is_number(c + 1))
            return (1);
        else
            return (0);
    }
    if (*c >= '0' && *c <= '9')
        return (1);
    else
        return (0);
}

int is_operator(char *c)
{
    if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%')
    {
        if (!is_number(c + 1))
            return (1);
        else
            return (0);
    }
    else
        return (0);
}

int rpn_calc(char *str, int *result)
{
    char *ptr = str;
    int *tab = (int *)malloc(sizeof(int)*5000);
    int i = -1;
    while (*ptr)
    {
        if (is_number(ptr))
        {
            ++i;
            tab[i] = atoi(ptr);
            ptr++;
            while (is_number(ptr))
                ptr++;
        }
        if (is_operator(ptr))
        {
            if ((i - 1) < 0)
                return (-1);
            if (*ptr == '/' || *ptr == '%')
                if (tab[i] == 0)
                    return (-1);
            if (*ptr == '+')
                tab[i - 1] = tab[i - 1] + tab[i];
            if (*ptr == '-')
                tab[i - 1] = tab[i - 1] - tab[i];
            if (*ptr == '*')
                tab[i - 1] = tab[i - 1] * tab[i];
            if (*ptr == '/')
                tab[i - 1] = tab[i - 1] / tab[i];
            if (*ptr == '%')
                tab[i - 1] = tab[i - 1] % tab[i];
            --i;
        }
        ptr++;
    }
    *result = tab[0];
    if (i != 0)
        return (-1);
    else
        return (1);
}
