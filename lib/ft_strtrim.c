/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:22:05 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:22 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_start(char const *s)
{
	unsigned int	start;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	return (start);
}

char				*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	start;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	start = ft_start(s);
	size = ft_strlen(s) - 1;
	if (s[start] == '\0')
		return (ft_memalloc(1));
	while (s[size] == ' ' || s[size] == '\n' || s[size] == '\t')
		size--;
	result = ft_strnew((size - start + 1));
	if (!result)
		return (NULL);
	while (i < size - start + 1)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
