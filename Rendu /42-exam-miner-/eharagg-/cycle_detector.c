/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:23:22 by eharrag-          #+#    #+#             */
/*   Updated: 2019/08/29 11:03:35 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

int		cycle_detector(const t_list *list)
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

int		main(void)
{
	t_list t_1;
	t_list t_2;
	t_list t_3;
	t_list t_4;
	t_list t_5;

	t_1.next = &t_2;
	t_2.next = &t_3;
	t_3.next = &t_4;
	t_4.next = &t_5;
	t_5.next = NULL;
	if (cycle_detector(&t_1) == 1)
		printf("Cycle FOUND.\n");
	else
		printf("Cycle NOT FOUND.\n");
	return (0);
}
