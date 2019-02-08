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
int			ft_checkerror(char **tab, int x, int y, char c);
char		**tabnew(size_t x);
char		**ft_algo(t_list *tetris, int p);
#endif
