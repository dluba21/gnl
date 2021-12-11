/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:45:17 by dluba             #+#    #+#             */
/*   Updated: 2021/12/05 18:58:02 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (-1);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(ft_strlen(str) + 1);
	if (ptr == NULL)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2, char c)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup("");
	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (str == NULL)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != c)
		str[i++] = s2[j++];
	str[i] = c;
	str[++i] = 0;
	free(s1);
	return (str);
}

int	ft_strchr(const char *str, int sym)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)sym)
			return (i);
		i++;
	}
	return (i);
}

char	*re_string(char *str, int flag)
{
	char	*temp;
	int		i;

	i = ft_strchr(str, '\n') + 1;
	str += i;
	temp = ft_strdup(str);
	str -= i;
	if (flag)
		free(str);
	return (temp);
}
