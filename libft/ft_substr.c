/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:49:29 by ialashqa          #+#    #+#             */
/*   Updated: 2023/12/03 18:00:58 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_length;

	if (s == NULL)
	{
		return (NULL);
	}
	s_length = ft_strlen(s);
	if (start >= s_length)
	{
		substr = malloc(1);
		if (substr != NULL)
			substr[0] = '\0';
		return (substr);
	}
	if (len > s_length - start)
	{
		len = s_length - start;
	}
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
