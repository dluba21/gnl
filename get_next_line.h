/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:45:34 by dluba             #+#    #+#             */
/*   Updated: 2021/12/05 18:58:32 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *c);
char	*ft_strjoin(char *s1, char *s2, char c);
int		ft_strchr(const char *str, int sym);
char	*re_string(char *str, int flag);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
#endif
