/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:15:50 by cazerini          #+#    #+#             */
/*   Updated: 2025/01/18 10:20:51 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_line(char **nextl, char *buf, int fd);
char	*ft_substr(char *str, char c);
char	*last_line(char *nextl, char c);
char	*ft_strjoin(char *nextl, char *buf);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup(char *buf);
int		ft_strchr(char *str, char c);

#endif
