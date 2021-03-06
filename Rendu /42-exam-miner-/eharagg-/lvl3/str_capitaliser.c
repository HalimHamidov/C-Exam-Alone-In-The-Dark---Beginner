/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitaliser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:56:25 by eharrag-          #+#    #+#             */
/*   Updated: 2018/09/13 12:57:38 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		tolower(char c)
{
	return (c += (c >= 'A' && c <= 'Z') ? 32 : 0);
}

int		toupper(char c)
{
	return (c -= (c >= 'a' && c <= 'z') ? 32 : 0);
}

void	str_capitaliser(char *s)
{
	while (*s)
	{
		while (ft_isspace(*s))
			ft_putchar(*s++);
		if (*s && !ft_isspace(*s))
			ft_putchar(toupper(*s++));
		while (*s && !ft_isspace(*s))
			ft_putchar(tolower(*s++));
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		++av;
		while (*av)
		{
			str_capitaliser(*av++);
			write(1, "\n", 1);
		}
	}
	return (0);
}
