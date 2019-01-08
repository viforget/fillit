/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:49:05 by medenis           #+#    #+#             */
/*   Updated: 2019/01/08 20:08:17 by medenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_paint(char **str)
{
	int				i;
	static char		c = 'A';

	i = 0;
	if (c > 'Z')
	{
		ft_putstr("error\n");
		return (-1);
	}
	while (i < 16)
	{
		if (str[i / 4][i % 4] == '#')
			str[i / 4][i % 4] = c;
		i++;
	}
	c++;
	return (1);
}

int		ft_painting(t_list *lst)
{
	int		error;

	i = 0;
	while (lst->next)
	{
		error = ft_paint(lst->content);
		lst = lst->next;
	}
	return (error);
}
