/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:22:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:14:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

int		ft_itoa_write(int n);
int		ft_to_hex(unsigned int n, char format);
int		ft_ptr_to_hex(void *ptr);
int		ft_printf(const char *str, ...);
int		ft_unsigned_to_str(unsigned int n);
int		ft_putchar_fd_printf(char c, int fd);
int		ft_putperc_fd_printf(int fd);
int		ft_putstr_fd_printf(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif