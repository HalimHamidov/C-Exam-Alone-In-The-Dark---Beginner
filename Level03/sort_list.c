#include <stdio.h>
#include <stdlib.h>

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct     s_list
{
    int            data;
    struct s_list  *next;
}                  t_list;

t_list    *sort_list(t_list* lst, int (*cmp)(int, int));
int ascending(int a, int b);

#endif

#include "ft_list.h"

int ascending(int a, int b)
{
    return (a <= b);
}
void    ft_swap(int *c, int *d)
{
    int tmp;
    tmp = *c;
    *c = *d;
    *d = tmp;
}

t_list *sort_list(t_list* lstm, int (*cmp)(int, int))
{
    t_list *begin = lst;
    t_list *future;
    
    
    while (lst)
    {
        future = lst->next;
        while (future)
        {
            if (!cmp(lst->data, future->data))
                ft_swap(&lst->data, &future->data);
            future = future->next;
        }
        lst = lst->next;
    }
    return (begin);
}
t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list  *begin = lst;
    t_list  *future;
    
    while (lst)
    {
        future = lst->next;
        while(future)
        {
        if (!cmp(lst->data, future->data))
            ft_swap(&lst->data, &future->data);
        future = future->next;
        }
        lst = lst->next;
    }
    return (begin);
}


t_list    *sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list  *begin = lst;
    t_list  *future;
    
    while (lst)
    {
        future = lst->next;
        while (future)
        {
            if (!cmp(lst->data, future->data))
                ft_swap(&lst->data, &future->data);
            future = future->next;
        }
        lst = lst->next;
    }
    return (begin);
}


//Assignment name  : sort_list
//Expected files   : sort_list.c
//Allowed functions:
//--------------------------------------------------------------------------------
//
//Write the following functions:
//
//t_list    *sort_list(t_list* lst, int (*cmp)(int, int));
//
//This function must sort the list given as a parameter, using the function
//pointer cmp to select the order to apply, and returns a pointer to the
//first element of the sorted list.
//
//Duplications must remain.
//
//Inputs will always be consistent.
//
//You must use the type t_list described in the file list.h
//that is provided to you. You must include that file
//(#include "list.h"), but you must not turn it in. We will use our own
//to compile your assignment.
//
//Functions passed as cmp will always return a value different from
//0 if a and b are in the right order, 0 otherwise.
//
//For example, the following function used as cmp will sort the list
//in ascending order:
//
//int ascending(int a, int b)
//{
//    return (a <= b);
//}

