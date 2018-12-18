/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 23:59:05 by viforget          #+#    #+#             */
/*   Updated: 2018/12/18 04:59:54 by viforget         ###   ########.fr       */
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
	size_t i;
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

char	**tabnew(size_t x, size_t y)
{
	char	**tab;
	char	*str;
	size_t	n;
	
	if (!(tab = (char **)malloc(sizeof(char *) * x)))
		return (NULL);
	return (tab);
}

/*void	ft_showtetris(t_list *list)
{
	while()
}*/

int		main(int argc, char **argv)
{
	t_list	*tetris;
	t_list	*list;
	char	*str;
	int		fd;
	int		nb;
	char	**tab;

	nb = 4;
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		tab = tabnew(4, 4);
		list = tetris;
		while(nb == 4)
		{
			nb = ft_filltab(fd, tab, 4);
			tetris->next = ft_lstnew(tab, sizeof(char *) * 4);
			tetris = tetris->next;
		}
		tetris = tetris->next;
		ft_puttab(tetris->content, 4);
	}
}
