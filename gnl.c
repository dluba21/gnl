#include "get_next_line.h"
#define BUF_SIZE	2
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

char	*ft_strdup(const char *str)
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
	free(str);
	return (&ptr[0]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
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
	if (sym == '\0')
		return (ft_strlen(str));
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	static char	*rem;
	int			ret;
	
	str = (char *)malloc(BUF_SIZE + 1)
	if (rem)
	{
		if (ft_strchr(rem, '\n'))
		{
			line = (char *)malloc(ft_strchr(rem, '\n') + 1);
			while (*rem != '\n')
				*line++ = *rem++;
			*line++ = *rem++;
			rem = ft_strdup(rem);
			return (line)
		}
		line = ft_strdup("");
		line = ft_strjoin(line, rem);
	}
	while (ret)
	{
		ret = read(fd, str, BUF_SIZE);
		if (ret)
		{
			if (ft_strchr(str, '\n'))
			{
				line = (char *)malloc(ft_strchr(str, '\n') + 1);
				while (*str != '\n')
					*line++ = *str++;
				*line++ = *str++;
				rem = ft_strdup(str);
				return (line)
			}
		}
		
		
	}
}
