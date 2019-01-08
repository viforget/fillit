/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadde.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:28:40 by viforget          #+#    #+#             */
/*   Updated: 2019/01/07 21:47:33 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadde(t_list **alst, t_list *new)
{
	t_list *lst;

	if(alst != NULL)
	{
		lst = *alst;
		if (lst != NULL)
		{
			while(lst->next)
				lst = lst->next;
			lst->next = new;
		}
		else
			*alst = new;
	}
}
