/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:46:28 by dluba             #+#    #+#             */
/*   Updated: 2021/12/05 18:58:02 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(char *c);
char	*ft_strjoin(char *s1, char *s2, char c);
int		ft_strchr(const char *str, int sym);
char	*re_string(char *str, int flag);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
#endif
