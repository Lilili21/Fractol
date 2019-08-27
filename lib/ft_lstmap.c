/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:54:07 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:22 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_elem;
	t_list		*temp_elem;
	t_list		*result;

	if (!lst || !f || !(new_elem = (t_list*)malloc(sizeof(t_list))) ||
	!(new_elem = f(lst)))
		return (NULL);
	result = new_elem;
	temp_elem = new_elem;
	lst = lst->next;
	while (lst)
	{
		if (!(new_elem = f(lst)))
		{
			ft_lstdel(&result, &ft_del);
			return (NULL);
		}
		temp_elem->next = ft_lstnew(new_elem->content, new_elem->content_size);
		temp_elem = temp_elem->next;
		lst = lst->next;
	}
	return (result);
}
