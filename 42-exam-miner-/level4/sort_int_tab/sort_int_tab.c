/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:15:21 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 11:41:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bubble Sort O(N*N)

/**************************** PASSES IN EXAM ***************************/

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j;
	int temp;

	while ( i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

//Assignment name  : sort_int_tab
//Expected files   : sort_int_tab.c
//Allowed functions:
//--------------------------------------------------------------------------------
//
//Write the following function:
//
//void sort_int_tab(int *tab, unsigned int size);
//
//It must sort (in-place) the 'tab' int array, that contains exactly 'size'
//members, in ascending order.
//
//Doubles must be preserved.
//
//Input is always coherent.

