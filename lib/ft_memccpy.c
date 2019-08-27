/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:22:13 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:22 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*a;
	unsigned char		*b;
	size_t				i;

	i = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (n > 0)
	{
		if (*b == (unsigned char)c)
		{
			*a++ = *b++;
			return ((void*)a);
		}
		*a++ = *b++;
		n--;
	}
	return (NULL);
}
