/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:15:50 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/23 18:20:41 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_line_b(char **nextl, char *buf, int fd);
char	*ft_substr_b(char *str, char c);
char	*last_line_b(char *nextl, char c);
char	*ft_strjoin_b(char *nextl, char *buf);
size_t	ft_strlen_b(const char *s);
char	*ft_strdup_b(char *buf);
int		ft_strchr_b(char *str, char c);

#endif