/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 02:24:17 by viforget          #+#    #+#             */
/*   Updated: 2019/02/04 22:39:37 by viforget         ###   ########.fr       */
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

void	ft_tabdel(char **tab, size_t j)
{
	size_t i;

	i = 0;
	if (tab != NULL)
	{
		while(i < j)
		{
			ft_strdel(&tab[i]);
			//free(&tab[i]);
			i++;
		}
		free(tab);
	}
}

char	**ft_try(char **bsqa, char **tetro, size_t piece, int d, size_t p)
{
	int		i;
	char	**bsquare;

	bsquare = ft_tabcopy(bsqa, p);
	i = 0;
	while (i <= 12)
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
				ft_tabdel(bsquare, p);
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
	tab2 = NULL;
	while (i <= piece * (piece - 1))
	{
		tab2 = tab;
		ft_tabdel(tab, piece);
		tab = ft_try(bsquare, tetris->content, tetris->content_size, i, piece);
		i++;
		if (tab == NULL)
		{
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
	ft_tabdel(tab, piece);
	return (NULL);
}

char	**ft_algo(t_list *tetris)
{
	int		i;
	char	**tab;

	tab = NULL;
	i = 2;
	while (!tab)
	{
		tab = ft_algor(ft_gensquare(i), tetris, i);
		i++;
	}
	return (tab);
}
