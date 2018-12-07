/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 23:59:05 by viforget          #+#    #+#             */
/*   Updated: 2018/12/07 01:04:36 by viforget         ###   ########.fr       */
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

void	ft_filltab(int fd, char **tab, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(get_next_line(fd, &tab[i]));
		i++;
	}
}

char	**tabnew(size_t x, size_t y)
{
	char	**tab;
	char	*str;
	size_t	n;

	tab = (char **)malloc(sizeof(char *) * x);
	/*while(n--)
		tab[n] = ft_strnew(y);
	tab[n] = ft_strnew(y);*/
	return (tab);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**tab;

	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		tab = tabnew(4, 4);
		ft_filltab(fd, tab, 4);
		ft_puttab(tab, 4);
	}
}
