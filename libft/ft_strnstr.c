/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:37:48 by axcallet          #+#    #+#             */
/*   Updated: 2022/10/11 13:55:52 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	i = 0;
	j = 0;
	if ((s1 == NULL || s2 == NULL) && n == 0)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str2[j] == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] == str1[i + j] && (i + ft_strlen(str2)) <= n)
		{
			if (str2[j + 1] == '\0')
				return (&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
