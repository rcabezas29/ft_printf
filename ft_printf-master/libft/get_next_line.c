/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchivert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:23:45 by tchivert          #+#    #+#             */
/*   Updated: 2019/09/04 05:13:35 by tchivert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fill_line(char **line, char **str)
{
	int	i;
	int	linel;
	int	strl;

	strl = ft_strlen(*str);
	if ((i = (ft_strchr(*str, '\n') > 0)))
	{
		if (!(*line = ft_strsub(*str, 0, ft_strchr(*str, '\n') - *str)))
			return (-1);
	}
	else
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
	}
	linel = ft_strlen(*line);
	if (!(*str = ft_strsub(*str, (linel + i), (strl - (linel + i)))))
		return (-1);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str[1024];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || fd > 1024 || !line || (!str[fd] && !(str[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		ft_strdel(&tmp);
	}
	if (ret == -1 || !*(tmp = str[fd]))
		return (ret == -1 ? -1 : 0);
	if (ft_fill_line(&*line, &str[fd]) == -1)
	{
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&tmp);
	return (!str[fd] && !ft_strlen(*line) ? 0 : 1);
}
