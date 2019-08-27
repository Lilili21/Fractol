/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:20:56 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/18 18:17:25 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	char	*result;
	size_t	i;

	result = ft_strnew(size);
	if (!s || !result)
		return (NULL);
	i = 0;
	while (size-- > 0)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
