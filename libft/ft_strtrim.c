/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:17:39 by axcallet          #+#    #+#             */
/*   Updated: 2022/10/05 12:43:23 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	if (s1[i] == '\0' || set[i] == '\0')
		return (ft_strdup(s1));
	while (s1[i] != '\0' && ft_check(s1[i], set) == 1)
		i++;
	j = ft_strlen(s1) - 1;
	while (j >= i && ft_check(s1[j], set) == 1)
		j--;
	str = ft_substr(s1, i, (j - i) + 1);
	return (str);
}
