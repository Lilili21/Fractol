/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:56:43 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/21 18:31:21 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchri(const char *s, int c)
{
	int		pos;

	pos = 0;
	while (s[pos])
	{
		if (s[pos] == (char)c)
			return (pos);
		pos++;
	}
	if (s[pos] == '\0')
		return (pos);
	return (0);
}

static int	ft_new_line(char **s, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = ft_strchri(s[fd], '\n');
	if (s[fd][len] == '\n')
	{
		*line = ft_strndup(s[fd], len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[12000];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || fd >= 12000 || read(fd, buf, 0) < 0 ||
	BUFF_SIZE <= 0)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd));
}
