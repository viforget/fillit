<<<<<<< HEAD
#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_square
{
	int			size;
	char		**array;
} t_square;

typedef struct s_tetro
{
	char	**tetro;
	int		h;
    int		l;
} t_tetro;

int			ft_normalize(t_list *tetris);
int			ft_painting(t_list *lst);
t_square	*resolve(t_list *list);
int			ft_checkerror(char **tab, int x, int y, char c);
char		**tabnew(size_t x);
char		**ft_algo(t_list *tetris, int p);
#endif
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:19:04 by medenis           #+#    #+#             */
/*   Updated: 2019/01/25 16:22:57 by medenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

t_list		*ft_normalize(t_list *tetris);
int			ft_painting(t_list *lst);
int			ft_checkerror(char **tab, int x, int y, char c);
char		**tabnew(size_t x);
char		**ft_algo(t_list *tetris);
#endif
>>>>>>> d6b630213ee642c536d6e367c5145b6d95502ba9
