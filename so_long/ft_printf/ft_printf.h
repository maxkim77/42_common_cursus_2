/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:52:26 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 21:52:34 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	check_sign(va_list *ap, const char format);
int	ft_print_arr(char *c, int i, int len);

int	ft_printf_c(char c);
int	ft_printf_s(char *str);
int	ft_printf_p(unsigned long long p);
int	ft_printf_di(long long n);
int	ft_printf_u(unsigned int n);
int	ft_printf_x(unsigned int n, char flag);

#endif
