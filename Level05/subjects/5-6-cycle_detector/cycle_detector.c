#include <stdio.h>
//#include "list.h"
typedef struct      s_list
{
    int data;
    struct s_list   *next;
}                   t_list;

int cycle_detector(const t_list *list)
{
    const t_list *l1 = list;
    const t_list *l2 = list;
    
    while (l1 && l2 && l2->next)
    {
        l1 = l1->next;
        l2 = l2->next->next;
        if (l1 == l2)
            return (1);
    }
    return (0);
}
int     main(void)
{
    t_list t1;
    t_list t2;
    t_list t3;
    
    t1.next = &t2;
    t2.next = &t3;
    t3.next = NULL;
    if (cycle_detector(&t1) == 1)
        printf("Found\n");
    else
        printf("No cycle\n");
    return (0);
}
//Assignment name  : cycle_detector
//Expected files   : cycle_detector.c
//Allowed functions: malloc, free
//--------------------------------------------------------------------------------
//
//Create a function named cycle_detector that takes a const t_list *list
//as argument, and check if the given linked list contains no cycles.
//
//A cycle is defined when you go at least twice through the same link, when you
//travel inside a linked list.
//
//This function should returnw 1 if it detects a cycle inside the given linked
//list, otherwise it returns 0.
//
//This function should be prototyped like this:
//
//    int        cycle_detector(const t_list *list)
//
//The type t_list is:
//
//    typedef struct     s_list
//    {
//        int            data;
//        struct s_list  *next;
//    }                  t_list;
//
//This type will be included in a header named "list.h". You don't have to turn-in
//your "list.h", we will use ours during the evaluation.

