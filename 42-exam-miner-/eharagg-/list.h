/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:06:27 by eharrag-          #+#    #+#             */
/*   Updated: 2019/08/29 11:08:31 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	int            data;
    struct s_list	*next;
}				t_list;

#include "list.h"
#include <stdio.h>

int cycle_detector(const t_list *list);
#endif
