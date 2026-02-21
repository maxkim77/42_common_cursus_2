/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:47:34 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 23:47:36 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*process_line(char **stash);
char	*read_from_fd(int fd);
char	*get_next_line_helper(char **stash, int fd);
char	*get_next_line_bonus(int fd);

#endif
