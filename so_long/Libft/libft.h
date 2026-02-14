/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:03:09 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 22:16:42 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_strlenn(const char *s);

#endif