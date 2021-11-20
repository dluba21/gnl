#include "get_next_line.h"
#define BUF_SIZE	10000
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i++]) ;
	return (--i);
}

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
	return (&ptr[0]);
}

char	*ft_strjoin(char const *s1, char const *s2, char c)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
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
	if (s1)
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

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	static char	*rem;
	int			ret;
	
	str = (char *)malloc(BUF_SIZE + 1);
	line = ft_strdup("");
	if (rem)
	{
		if (ft_strchr(rem, '\n') != ft_strlen(rem))
		{
			line = ft_strjoin(line, rem, '\n');
			rem += ft_strchr(rem, '\n') + 1;
			rem = ft_strdup(rem);
			return (line);
		}
		line = ft_strdup("");
		line = ft_strjoin(line, rem, '\0');
	}
	ret = 1;
	while (ret)
	{
		ret = read(fd, str, BUF_SIZE);
		if (ret)
		{
			if (ft_strchr(str, '\n') != ft_strlen(str))
			{
				line = ft_strjoin(line, str, '\n');
				str += ft_strchr(str, '\n') + 1;
				rem = ft_strdup(str);
				return (line);
			}
			if (!line)
				line = ft_strdup("");
			line = ft_strjoin(line, str, '\0');
		}
	}
	if (line)
		return (line);
	return (NULL);
}

int main()
{
	int fd;
	int n = 5;

	fd = open("aboba",  O_RDONLY);
	if (fd < 0)
		printf("error 1");
//	while (n--)
//	{
		printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
	printf("[%s]", get_next_line(fd));
//	printf("[%s]", get_next_line(fd));
//	printf("[%s]", get_next_line(fd));
	
//		printf("\n/////////////////////////////////\n");
//	}
}
