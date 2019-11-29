/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:11:41 by maparmar          #+#    #+#             */
/*   Updated: 2019/11/27 21:56:49 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"
void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c;	// Символ начала
	c = tab[begin.y][begin.x]; // Сохраняем символ начала

	tab[begin.y][begin.x] = 'F'; // Присваиваем начальной координате заполнения
	begin.y++; // Смещаемся на строку вниз
	if (begin.y < size.y && tab[begin.y][begin.x] == c) // when the position + 1 in Y Direction is the given character
		flood_fill(tab, size, begin);
	begin.y--; // Смещаемся на две строки вверх
	begin.y--;
	if (begin.y >= 0 && tab[begin.y][begin.x] == c) // when the position - 1 in Y Direction is the given character
		flood_fill(tab, size, begin);
	begin.y++;
	begin.x++;
	if (begin.x < size.x && tab[begin.y][begin.x] == c) //when the position +1 in X Direction is the given character;
		flood_fill(tab, size, begin);
	begin.x--;
	begin.x--;
	if (begin.x >= 0 && tab[begin.y][begin.x] == c) // when the position - 1 in X Direction is the given character;
		flood_fill(tab, size, begin);
}
