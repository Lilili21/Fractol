/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:22:00 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:22 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *s, char c)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			result++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (result);
}

static char	**ft_result(char const *s, char **result, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			result[k++] = ft_strndup(s + j, i - j);
			if (!result)
				ft_strdel(result);
		}
	}
	result[k] = 0;
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;

	if (!s || !c)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_words_count(s, c) + 1));
	if (!result)
		return (NULL);
	return (ft_result(s, result, c));
}
