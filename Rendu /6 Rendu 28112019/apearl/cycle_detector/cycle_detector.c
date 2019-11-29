#include "list.h"

int        cycle_detector(const t_list *list)
{
    t_list *l1 = list;
    t_list *l2 = list;
    
    while (l1 && l2 && l2->next)
    {
        l1 = l1->next;
        l2 = l2->next->next;
        if (l1 == l2)
            return (0);
    }
    return (1);
}
