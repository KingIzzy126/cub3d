/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:16:18 by ialashqa          #+#    #+#             */
/*   Updated: 2023/12/06 10:07:58 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **s, int i)
{
	int	j;

	j = i;
	while (j >= 0)
	{
		if (s[j] == NULL)
		{
			while (i >= 0)
			{
				if (s[i] != NULL)
				{
					free(s[i]);
				}
				i--;
			}
			free(s);
			return (NULL);
		}
		j--;
	}
	return (s);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
		{
			s++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	len;
	char	**split_str;

	if (s == 0)
		return (NULL);
	split_str = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (split_str == 0)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = 0;
			while (*s != '\0' && *s != c && ++len)
				s++;
			split_str[i] = ft_substr(s - len, 0, len);
			i++;
		}
		else
			s++;
	}
	split_str[i] = NULL;
	return (free_split(split_str, i - 1));
}
