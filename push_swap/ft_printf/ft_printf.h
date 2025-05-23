/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:34:25 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 11:34:27 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_conversions(char *str, va_list *arg);
int		ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		ft_to_hex(unsigned int num, int fd, char c);
int		ft_print_memory_address(void *ptr, int fd);
#endif