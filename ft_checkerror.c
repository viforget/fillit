/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:07:14 by viforget          #+#    #+#             */
/*   Updated: 2019/01/18 19:08:11 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_checkerror(char **tab, int x, int y, char c)
{
	int i;

	i = 0;
	if (y < 3)
		if (tab[x][y + 1] == '#')
			i++;
	if (x < 3)
		if (tab[x + 1][y] == '#')
			i++;
	if (y > 0)
		if (tab[x][y - 1] == c)
			i++;
	if (x > 0)
		if (tab[x - 1][y] == c)
			i++;
	return (i);
}
