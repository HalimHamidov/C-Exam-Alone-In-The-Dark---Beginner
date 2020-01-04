/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:17:58 by draudrau          #+#    #+#             */
/*   Updated: 2018/09/11 20:08:27 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	epur_str(char *str)
{
  char	sp;
  int	i;

  sp = -1;
  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  if (sp == 1)
	    my_putchar(' ');
	  sp = 0;
	  my_putchar(str[i]);
	}
      else if (sp == 0)
	sp = 1;
      i++;
    }
}

int	main(int argc, char **argv)
{
  if (argc > 1)
    epur_str(argv[1]);
  my_putchar('\n');
  return (0);
}
