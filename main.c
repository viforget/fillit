/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 23:59:05 by viforget          #+#    #+#             */
/*   Updated: 2019/01/08 19:53:00 by medenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	p(void)
{
	static int n = 'A';

	ft_putchar(n);
	ft_putchar('\n');
	n++;
}

int		ft_filltab(int fd, char **tab, size_t n)
{
	size_t	i;
	int		nb;
	char	*trash;

	i = 0;
	while (i < n)
	{
		nb = get_next_line(fd, &tab[i]);
		i++;
	}
	get_next_line(fd, &trash);
	return (nb);
}

char	**tabnew(size_t x)
{
	char	**tab;
	
	if (!(tab = (char **)malloc(sizeof(char *) * x)))
		return (NULL);
	return (tab);
}

int		main(int argc, char **argv)
{
	t_list	*tetris;
	t_list	*tetro;
	int		fd;
	int		nb;
	char	**tab;
	int		a = 15;

	nb = 1;
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		tab = tabnew(4);
		tetris = NULL;
		while (nb == 1)
		{
			nb = ft_filltab(fd, tab, 4);

			tetro = ft_lstnew(tab, sizeof(char *) * 4);
			ft_lstadde(&tetris, tetro);
		}
		ft_normalize(tetris);
		while (a--)
		{
			//ft_putchar('\n');
			//a = ft_paint(tetris->content);
			ft_puttab(tetris->content, 4);
			tetris = tetris->next;
		}
		//ft_putchar('\n');
		//tetris = tetris->next;
		//ft_puttab(tetris->content, 4);
		//ft_putchar('\n');
	}
}
