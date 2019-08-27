/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:11:52 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:22 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t d_size;
	size_t s_size;
	size_t result;
	size_t i;

	d_size = ft_strlen(dest);
	s_size = ft_strlen(src);
	i = 0;
	result = s_size;
	if (n <= d_size)
		result += n;
	else
		result += d_size;
	while (src[i] != '\0' && (d_size + 1) < n)
	{
		dest[d_size] = src[i];
		i++;
		d_size++;
	}
	dest[d_size] = '\0';
	return (result);
}
