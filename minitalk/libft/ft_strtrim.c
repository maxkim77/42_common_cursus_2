/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2025/05/06 17:29:05 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issep(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_startinit(size_t i, char const *s1, char const *set)
{
	while (s1[i] && ft_issep(s1[i], set))
		i++;
	return (i);
}

static size_t	ft_endinit(size_t j, char const *s1, char const *set)
{
	if (!s1 || j == 0)
		return (0);
	while (j > 0 && ft_issep(s1[j], set))
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = ft_startinit(0, s1, set);
	j = ft_endinit(ft_strlen(s1) - 1, s1, set);
	k = 0;
	if (i > j)
		return (ft_strdup(""));
	tab = malloc(sizeof(char) * ((j - i) + 2));
	if (!tab)
		return (NULL);
	while (i <= j)
		tab[k++] = s1[i++];
	tab[k] = '\0';
	return (tab);
}
