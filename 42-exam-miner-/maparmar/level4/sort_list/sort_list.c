#include "list.h"

int ascending(int a, int b) // function used to compare a and b and return 1 if they are in ascending order or else 0.
{
	return (a <= b);
}

// Меняем значения чисел int по адресам
void	ft_swap(int *c, int *d) // swap funtion used to swap the data of c and d.
{
	int	temp;

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

//
//#include "list.h"
//
//t_list *head; // global variable to excess the list.
//
//t_list *ft_create(int item) // function to create a new node in list
//{
//    t_list *new;
//
//    if (!(new = (t_list *)malloc(sizeof(t_list))))
//        return NULL;
//    new->data = item;
//    new->next = NULL;
//    return (new);
//}
//
//static int  push(int item) // will push the item to the list
//{
//    t_list *new = ft_create(item);
//    if (!new)
//        return 0;
//    new->next = head;
//    head = new;
//    return 1;
//}
//
//
//void ft_print(t_list *h) // Function to print the elements in the list.
//{
//    if (h == NULL)
//        return ;
//    else
//    {
//        printf("%d", h->data);
//        ft_print(h->next);
//    }
//}
//int main (void) // main driver
//{
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
//    push(arr[0]);
//    push(arr[1]);
//    push(arr[2]);
//    push(arr[3]);
//    push(arr[9]);
//
//    int (*cmp)(int, int) = &ascending; // functional pointer which will compare the elements and return 1 or 0;
//    sort_list(head, cmp); // sort list will sort the elements in ascending order.
//    ft_print(head); // print all the elements in the list.
//    return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct s_list t_list;
//
//struct s_list
//{
//    int     data;
//    t_list  *next;
//};
//
//t_list    *sort_list(t_list* lst, int (*cmp)(int, int)); // defination of the function.
//int        ascending(int a, int b); // defination of the functional pointer which will be used to compare a and b.

