/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:41:41 by axcallet          #+#    #+#             */
/*   Updated: 2022/10/13 16:13:44 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && k == 0)
		{
			k = 1;
			j++;
		}
		else if (s[i] == c)
			k = 0;
		i++;
	}
	return (j);
}

static int	ft_count_char(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] == c)
		j++;
	while (s[i + j] != c && s[i + j] != '\0')
		i++;
	return (i);
}

static void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
}

static void	ft_algo_split(const char *s, char c, char **tab, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c && j < ft_count_word(s, c))
		{
			tab[j] = ft_calloc(sizeof(char), ft_count_char(&s[i], c) + 1);
			if (!tab)
			{
				ft_free(tab);
				return ;
			}
			ft_strlcpy(tab[j], &s[i], ft_count_char(&s[i], c) + 1);
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i])
			i++;
	}
	tab[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (s == 0)
		return (NULL);
	tab = ft_calloc(sizeof(char *), (ft_count_word(s, c)) + 1);
	if (!tab)
		return (NULL);
	ft_algo_split(s, c, tab, i);
	return (tab);
}
