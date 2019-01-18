/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:50:22 by viforget          #+#    #+#             */
/*   Updated: 2019/01/18 19:04:10 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

t_list	*ft_normalize(t_list *tetris);
int		ft_painting(t_list *tetris);
int		ft_checkerror(char **tab, int x, int y, char c);
#endif
