/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 02:24:17 by viforget          #+#    #+#             */
/*   Updated: 2019/01/22 18:04:09 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_gensquare(i)
{
	char **tab;
	int		x;

	x = i;
	tab = tabnew(i);
	while(x)
	{
		x--;
		if (!(tab[x] = (char *)ft_memalloc(sizeof(char) * i)))
			return (NULL);
		ft_memset(tab[x], '.', i);
	}
	return (tab);
}

char	**ft_tabcopy(char **tab, size_t i)
{
	char	**tab2;
	int		j;

	j = 0;
	tab2 = tabnew(i);
	while(j < i)
	{
		if (!(tab2[j] = ft_strdup(tab[j])))
			return (NULL);
		j++;
	}
	return (tab2);
}

char	**ft_try(char **bsqa, char **tetro, size_t piece, int d, size_t p)
{
	int		i;
	char	**bsquare;

	bsquare = bsqa;
	i = 0;
	while (i < p * (p - 1))
	{
		if (tetro[i / p][i % p] != '.')
		{
			if (bsquare[i / 4 + d / p][i % 4 + d % 4] && 
					bsquare[i / 4 + d / p][i % 4 + d % 4] == '.')
				bsquare[i / 4 + d / p][i % 4 + d % 4] = tetro[i / p][i % p];
			else
			{
				ft_putnbr(i);
				return (NULL);
			}
		}
		i++;
	}
	return (bsquare);
}

char	**ft_algor(char **bsquare, t_list *tetris, size_t piece)
{
	char	**tab;
	char	**tab2;
	size_t		i;

	i = 0;
	tab = NULL;
	while (i <= 12)
	{
		
		tab = ft_try(bsquare, tetris->content, tetris->content_size, i, piece);
		i++;
		if (tab && tetris->next)
			tab = ft_algor(tab, tetris->next, piece);
	}
	return (tab);
}

char	**ft_algo(t_list *tetris)
{
	int		i;
	char	**tab;

	tab = NULL;
	i = 0;
	while (1)
	{
		ft_algor(ft_gensquare(i), tetris, i);
		i++;
	}
}
