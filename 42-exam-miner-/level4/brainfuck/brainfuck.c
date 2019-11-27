/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:32:17 by maparmar          #+#    #+#             */
/*   Updated: 2019/11/27 22:47:37 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	brainfuck(char *str)
{
	int	tab[2048] = {0};
	int	*ptr;
	int	loop_count;

	ptr = tab;
	loop_count = 0;
	while (*str)
	{
		if (*str == '>')
			ptr++; // перемещение по указателю
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			++(*ptr); // Инкременция
		else if (*str == '-')
			--(*ptr);
		else if (*str == '.') // Вывод
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
		{
			loop_count = 1;
			while (loop_count != 0)
			{
				str++; // Увеличивается до тех пор: пока нет закрывающейся скобки
				if (*str == ']')
					--loop_count;
				if (*str == '[')
					++loop_count;
			}
		}
		else if (*str == ']' && *ptr != 0)
		{
			loop_count = 1;
			while (loop_count != 0)
			{
				str--; // Уменьшается до тех пор, пока нет открывающейся скобки
				if (*str == '[')
					--loop_count;
				if (*str == ']')
					++loop_count;
			}
		}
		str++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		brainfuck(argv[1]);
	return (0);
}
