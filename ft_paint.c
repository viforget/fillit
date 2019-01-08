/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:20:27 by viforget          #+#    #+#             */
/*   Updated: 2019/01/08 18:22:04 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int    ft_paint(char **str)
{
	int         i;
	static char     c = 'A';

	i = 0;
	if (c > 'Z')
	{
		ft_putstr("error\n");
		return (-1);
	}
	while (i < 16)
	{
		if (str[i/4][i%4] == '#')
			str[i/4][i%4] = c;
		i++;
	}
	c++;
	return(1);
}
