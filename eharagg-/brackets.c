/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:55:40 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/14 10:52:06 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int checkpair(char c, char cc)
{
	if ((c == ')' && cc == '(') || (c == '}' && cc == '{') || (c == ']' && cc == '['))
		return (1);
	return (0);
}

int check(char *str)
{
	int		i;
	char	buf[2048];
	int		count = 0;

	i = -1;
	while (*str)
	{
		if (*str == '(' || *str == '{' || *str == '[')
		{
			i++;
			count++;
			buf[i] = *str;
		}
		if (*str == ')' || *str == '}' || *str == ']')
		{
			if (checkpair(*str, buf[i]) == 1)
			{
				i--;
				count++;
			}
			else
				return (1);
		}
		if (count % 2 != 0)
			return (1);
		str++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
		write(1, "\n", 1);
	else
	{
		while (i < ac)
		{
			if (check(av[i]) == 0)
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	return (0);
}
