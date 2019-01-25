/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 02:24:17 by viforget          #+#    #+#             */
/*   Updated: 2019/01/25 16:30:25 by medenis          ###   ########.fr       */
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
	size_t		j;

	if (tab == NULL)
		return (NULL);
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

char	**ft_try(char **bsqa, char **tetro, int d, size_t p)
{
	size_t		i;
	char	**bsquare;

	bsquare = ft_tabcopy(bsqa, p);
	i = 0;
	while (i <= 12 && i <= (p * (p - 1)))
	{
		if (tetro[i / 4][i % 4] != '.')
		{
			if (((i / 4 + d / p) < p) && ((i % 4 + d % p) < p) &&
					bsquare[i / 4 + d / p][i % 4 + d % p] == '.')
			{
				bsquare[i / 4 + d / p][i % 4 + d % p] = tetro[i / 4][i % 4];
			}
			else
			{
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
	while (i <= piece * (piece - 1))
	{
		tab2 = ft_tabcopy(tab, piece);
		tab = ft_try(bsquare, tetris->content, i, piece);
		i++;
		if (tab == NULL)
		{
			//penser a creer ft_tabdel
			tab = ft_tabcopy(tab2, piece);
		}
		else if (tetris->next)
		{
			tab = ft_algor(tab, tetris->next, piece);
		}
		if (tab)
		{
			return (tab);
		}
	}
	return (NULL);
}

char	**ft_algo(t_list *tetris)
{
	int		i;
	char	**tab;

	tab = NULL;
	i = 4;
	while (!tab)
	{
		tab = ft_algor(ft_gensquare(i), tetris, i);
		i++;
	}
	return (tab);
}
