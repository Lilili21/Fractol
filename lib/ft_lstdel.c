/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:46:16 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:22 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (!alst || !*alst)
		return ;
	tmp = *alst;
	next = *alst;
	if (del)
	{
		while (tmp != NULL)
		{
			next = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = next;
		}
		*alst = NULL;
	}
}
