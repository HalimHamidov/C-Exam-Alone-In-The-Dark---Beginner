#include "list.h"

int ascending(int a, int b) // function used to compare a and b and return 1 if they are in ascending order or else 0.
{
	return (a <= b);
}
void ft_swap(int *c, int *d) // swap funtion used to swap the data of c and d.
{
	int temp;
	temp = *c;
	*c = *d;
	*d = temp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *begin = lst; // pointer used to point head of the list.
	t_list *future; // pointer used for seconding while loop which will make the bubble (largest element) at the last of the list.
	while(lst)
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