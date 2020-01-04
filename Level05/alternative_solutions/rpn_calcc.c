#include <unistd.h>
#include <stdio.h>

int is_number(char *c);
int is_operator(char *c);
int rpn_calc(char *str, int *restult);

int main(int argc, char **argv)
{
    int result;
    result = 0;
    
    if (argc != 0)
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
    if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c '%')
    {
        if (is_number(c+1))
            return (1);
        else
            return (0);
    }
    if (*c <= '9' && *c >= '0')
        return (1);
    else
        return (0);
}

int is_operator(char *c)
{
    if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c '%')
    {
        if (!is_number(c+1))
            return (1);
        else
            return (0);
    }
        return (0);
}

int rpn_calc(char *str, int *result)
{
    char *ptr;  // initialize pointer ptr for *str,
    int *tab;  // initialize pointer tab for *result array of ints
    int i;   // initialize counter i
    
    tab = (int *)malloc(sizeof(int)*5000); // allocate memory for tab
    i = -1; //start with -1 so that the initial value was 0
    ptr = str;  // work with pointer ptr vs str
    while (*ptr)
    {
        // to assign ptr number of operator / if ptr is number then assign tab[i] as integer and increment string further
        if(is_number(ptr))
        {
            i++;  // increase counter
            tab[i] = atoi(ptr); // tab atoi
            ptr++; // increase ptr
            while (is_number(ptr))// increase ptr in string while condition
                ptr++;
        }
        // operations with ptr +-*/%
        if(is_operator(ptr))
        {
            if ((i-1)<0)
                return (-1);
            if (*ptr == '/' || *ptr == '%')
                if (tab[i] == 0)
                    return (-1);
            if (*ptr == '+')
                tab[i-1] = tab[i-1] + tab[i];
            if (*ptr == '-')
                tab[i-1] = tab[i-1] - tab[i];
            if (*ptr == '*')
                tab[i-1] = tab[i-1] * tab[i];
            if (*ptr == '/')
                tab[i-1] = tab[i-1] / tab[i];
            if (*ptr == '%')
                tab[i-1] = tab[i-1] % tab[i];
            i--;
        }
        ptr++;
    }
    // result
    *result = tab[0];
    if (i != 0)  // must have condition for cheching EOF
        return (-1);
    else
        return (1); // this is grear example working with true or false condition 1 or 0.
}


#include <stdlib.h>
#include <stdio.h>

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
    char *ptr;
    int *tab;
    int i;

    tab = (int *)malloc(sizeof(int) * 5000);
    i = -1;
    ptr = str;
    while (*ptr)
    {
        if (is_number(ptr))
        {
            i++;
            tab[i] = atoi(ptr);
            ptr++;
            while (is_number(ptr))
                ptr++;
        }
        if (is_operator(ptr))
        {
            if ((i - 1) < 0)
                return (-1);
            if (*ptr == '/'|| *ptr == '%')
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
            i--;
        }
        ptr++;
    }
    *result = tab[0];
    if (i != 0)
        return (-1);
    else
        return (1);
}

int main(int ac, char **av)
{
    int result;

    result = 0;
    if (ac != 2)
        printf("Error\n");
    else
    {
        if (rpn_calc(av[1], &result) == -1)
            printf("Error\n");
        else
            printf("%d\n", result);
    }
    return (0);
}

int rpn_calc(char *str, int *result)
{
    char *ptr;
    ptr = str;
    int *tab;
    tab = (int *)malloc(sizeof(int)*5000);
    int i = -1;
    
while (*ptr)
{
    if (is_number(ptr))
    {
        i++;
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
            if(tab[0] == 0)
                return (-1);
        if (*ptr == '+')
            tab[i-1] = tab[i-1] + tab[i];
        if (*ptr == '-')
            tab[i-1] = tab[i-1] - tab[i];
        if (*ptr == '*')
            tab[i-1] = tab[i-1] * tab[i];
        if (*ptr == '/')
            tab[i-1] = tab[i-1] / tab[i];
        if (*ptr == '%')
            tab[i-1] = tab[i-1] & tab[i];
        i--;
    }
    ptr++;
}
*result = tab[0];
if (i != 0)
    return (-1);
else
    return (1);
}
    if (is_operator(ptr))
    {
        if ((i - 1)<0)
            return (-1);
        if (*ptr == '?' || *ptr == '%')
            if (tab[0] == 0)
                return (-1);
        if (*ptr == '+')
            tab[i-1] = tab[i-1] + tab[i];
        if (*ptr == '-')
            tab[i-1] = tab[i-1] - tab[i];
        if (*ptr == '*')
            tab[i-1] = tab[i-1] * tab[i];
        if (*ptr == '/')
            tab[i-1] = tab[i-1] / tab[i];
        if (*ptr == '%')
            tab[i-1] = tab[i-1] % tab[i];
        i--;
    }
    ptr++;
}
