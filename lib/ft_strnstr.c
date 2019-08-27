/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:04:35 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:22 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1[i] && i < n)
	{
		while (s1[i] && s2[j] && s1[i] == s2[j] && i < n)
		{
			i++;
			j++;
		}
		if (j == ft_strlen(s2))
			return ((char *)s1 + i - j);
		else
			i = (i - j) + 1;
		j = 0;
	}
	return (NULL);
}
