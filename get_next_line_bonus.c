/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:44:38 by dluba             #+#    #+#             */
/*   Updated: 2021/12/05 18:58:01 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	rem_checker(char **line, char **rem)
{
	if (*rem)
	{
		if (ft_strchr(*rem, '\n') != ft_strlen(*rem))
		{
			*line = ft_strjoin(*line, *rem, '\n');
			*rem = re_string(*rem, 1);
			return (1);
		}
		*line = ft_strjoin(*line, *rem, '\0');
	}
	return (0);
}

int	memory_deleter(char **rem, char **line, int ret)
{
	if (ft_strlen(*line) > 0)
	{
		free(*rem);
		*rem = NULL;
		return (1);
	}
	if (*rem && ret == 0)
	{
		if (ft_strlen(*rem) == 0)
		{
			free(*rem);
			*rem = NULL;
		}
	}
	return (0);
}

int	reader(char **line, char **rem, int fd)
{
	char	str[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, str, BUFFER_SIZE);
		str[ret] = 0;
		if (ret >= 0)
		{
			if (ft_strchr(str, '\n') != ft_strlen(str))
			{
				*line = ft_strjoin(*line, str, '\n');
				free(*rem);
				*rem = re_string(str, 0);
				return (1);
			}
			*line = ft_strjoin(*line, str, '\0');
		}
	}
	if (memory_deleter(rem, line, ret))
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rem[OPEN_MAX];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (rem_checker(&line, &(rem[fd])) == 1)
		return (line);
	if (reader(&line, &(rem[fd]), fd) == 1)
		return (line);
	free(line);
	return (NULL);
}
