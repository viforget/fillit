/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 23:59:05 by viforget          #+#    #+#             */
/*   Updated: 2019/02/07 22:46:20 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (trash[0])
		return (-1);
	return (nb);
}

char	**tabnew(size_t x)
{
	char	**tab;
	
	if (!(tab = (char **)malloc(sizeof(char *) * x)))
		return (NULL);
	return (tab);
}

/*int		main(int argc, char **argv)
{
	t_list	*tetris;
	t_list	*tetro;
	int		fd;
	int		nb;
	char	**tab;

	nb = 1;
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		tab = tabnew(4);
		tetris = NULL;
		while (nb == 1)
		{
			nb = ft_filltab(fd, tab, 4);
			if (nb == -1)
				return (0);
			if (nb == 1)
			{
				tetro = ft_lstnew(tab, sizeof(char *) * 4);
				ft_lstadde(&tetris, tetro);
			}
		}
		nb = ft_normalize(tetris);
		if (ft_painting(tetris) == -1)
		{
			ft_putstr("error\n");
			return (0);
		}
		tetro = tetris;
		char **tet;
		tet = ft_algo(tetris, nb);
		ft_puttab(tet, ft_strlen(tet[0]));
	}
}*/
