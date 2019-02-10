/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 02:24:17 by viforget          #+#    #+#             */
/*   Updated: 2019/02/10 02:40:55 by viforget         ###   ########.fr       */
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
		if (!(tab[x] = (char *)ft_memalloc(sizeof(char) * i + 1)))
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

void	ft_tabdel(char **tab, size_t j)
{
	size_t i;

	i = 0;
	if (tab != NULL)
	{
		while(i < j)
		{
			ft_strdel(&tab[i]);
			//free(tab[i]);
			i++;
		}
		ft_memdel((void **)&tab);
	}
}

char	**ft_try(char **bsquare, char **tetro, size_t piece, int d, size_t p)
{
	size_t		i;
	char		c;

	c = 'a';
	i = 0;
	while (i <= 12)
	{
		if (tetro[i / 4][i % 4] != '.')
		{
			if (((i / 4 + d / p) < p) && ((i % 4 + d % p) < p) &&
					bsquare[i / 4 + d / p][i % 4 + d % p] == '.')
			{
				c = tetro[i /4][i % 4];
				bsquare[i / 4 + d / p][i % 4 + d % p] = tetro[i / 4][i % 4];
			}
			else
			{
				ft_cleantab(bsquare, p, c);
				return (NULL);
			}
		}
		i++;
	}
	return (bsquare);
}

char	**ft_algor(char **bsquare, t_list *tetris, size_t piece, char c)
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
		ft_cleantab(bsquare, piece, c);
		tab = ft_try(bsquare, tetris->content, tetris->content_size, i, piece);
		i++;
		if (tab == NULL)
		{
			tab = ft_tabcopy(tab2, piece);
		}
		else if (tetris->next)
		{
			tab = ft_algor(tab, tetris->next, piece, c + 1);
		}
		if (tab)
		{
			return (tab);
		}
	}
	ft_tabdel(tab, piece);
	return (NULL);
}

char	**ft_algo(t_list *tetris, int p)
{
	int		i;
	char	**tab;

	tab = NULL;
	i = ft_sqrtp(p * 4);
	while (!tab)
	{
		tab = ft_algor(ft_gensquare(i), tetris, i, 'A');
		i++;
	}
	return (tab);
}
/*
int main()
{
	char **tab;

	while(1)
	{
		tab = ft_gensquare(700);
		ft_tabdel(tab, 700);
	}
}
*/
