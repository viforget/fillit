/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:49:05 by medenis           #+#    #+#             */
/*   Updated: 2019/01/18 19:04:14 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_paint(char **str)
{
	int				i;
	static char		c = 'A';
	int				count;
	int				ct;


	ct = 0;
	count = 0;
	i = 0;
	if (c > 'Z')
		return (-1);
	while (i < 16)
	{
		if (str[i / 4][i % 4] != '#' && str[i / 4][i % 4] != '.')
			return (-1);
		if (str[i / 4][i % 4] == '#')
		{
			ct += ft_checkerror(str, i / 4, i % 4, c);
			str[i / 4][i % 4] = c;
			count++;
		}
		i++;
	}
	c++;
	if (count != 4 || i != 16 || (ct != 6 && ct != 8))
		return (-1);
	return (1);
}

int		ft_painting(t_list *lst)
{
	int		error;

	error = 0;
	while (lst->next && error >= 0)
	{
		error = ft_paint(lst->content);
		lst = lst->next;
	}
	return (error);
}
