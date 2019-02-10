#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

int			ft_normalize(t_list *tetris);
int			ft_painting(t_list *lst);
int			ft_checkerror(char **tab, int x, int y, char c);
char		**tabnew(size_t x);
char		**ft_algo(t_list *tetris, int p);
void		ft_cleantab(char **tab, int p, char c);
#endif
