/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:34:01 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/14 14:03:38 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_countword(const char *s, const char c)
{
	unsigned int	i;
	char			is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			is_word = 1;
			s++;
		}
		if (is_word)
		{
			is_word = 0;
			i++;
		}
		if (!*s++)
			break ;
	}
	return (i);
}

static int	ft_getwordsize(char **s, const char c)
{
	int	i;

	i = 0;
	while (**s == c)
		(*s)++;
	while (**s && *(*s)++ != c)
		i++;
	return (i);
}

static void	ft_freearray(char **array)
{
	char	**tmp;

	tmp = array;
	while (*tmp)
		free(*tmp++);
	free(array);
}

static char	**ft_fillarray(char **array, const char *s, const char c)
{
	int		i;
	char	**tmp;

	tmp = array;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			(*tmp)[i++] = *s++;
		(*tmp)[i] = '\0';
		tmp++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char			**array;
	char			*tmp;
	unsigned int	i;
	unsigned int	arraysize;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	i = 0;
	arraysize = ft_countword(s, c);
	array = (char **)malloc((arraysize + 1) * sizeof(char *));
	if (!array)
		return (0);
	while (i < arraysize)
	{
		array[i] = (char *)malloc(ft_getwordsize(&tmp, c) + 1);
		if (!array[i])
		{
			ft_freearray(array);
			return (NULL);
		}
		i++;
	}
	array[arraysize] = NULL;
	return (ft_fillarray(array, s, c));
}
