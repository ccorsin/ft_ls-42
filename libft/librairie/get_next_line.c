/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:03 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 15:03:20 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_read(char **cash, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		r;

	r = read(fd, buf, BUFF_SIZE);
	if (r == -1)
		return (-1);
	buf[r] = '\0';
	tmp = *cash;
	if (!(*cash = ft_strjoin(tmp, buf)))
		return (-1);
	free(tmp);
	return (r);
}

static int		ft_line(char **cash, char **line, char *tmp)
{
	char	*s;
	int		i;

	i = 0;
	while ((*cash)[i] != '\n')
		i++;
	if (!(*line = ft_strndup(*cash, i)))
		return (-1);
	s = *cash;
	if (!(*cash = ft_strdup(tmp + 1)))
		return (-1);
	free(s);
	return (1);
}

static int		ft_end_line(char **cash, char **line)
{
	if (!(*line = ft_strdup(*cash)))
		return (-1);
	if (ft_strlen(*cash) != 0)
	{
		if (!(*cash = ft_strnew(1)))
			return (-1);
		return (1);
	}
	ft_strdel(cash);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *cash;
	int			r;
	char		*tmp;

	if (fd == -1 || (!cash && !(cash = ft_strnew(1))))
		return (-1);
	r = BUFF_SIZE;
	while (r >= 0)
	{
		tmp = cash;
		while (*tmp != '\0' || r < BUFF_SIZE)
		{
			if (*tmp == '\n')
				return (ft_line(&cash, line, tmp));
			if (*tmp == '\0')
				return (ft_end_line(&cash, line));
			tmp++;
		}
		r = ft_read(&cash, fd);
		if (r == -1)
			return (-1);
	}
	return (0);
}
