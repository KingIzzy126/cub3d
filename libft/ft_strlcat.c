/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:16:00 by ialashqa          #+#    #+#             */
/*   Updated: 2023/11/23 10:54:37 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	m;
	size_t	n;
	size_t	i;

	n = ft_strlen(dst);
	m = ft_strlen(src);
	i = 0;
	if (dstsize <= n)
	{
		return (dstsize + m);
	}
	while (src[i] != '\0' && (n + i + 1) < dstsize)
	{
		dst[n + i] = src[i];
		i++;
	}
	if (n + i < dstsize)
	{
		dst[n + i] = '\0';
	}
	return (n + m);
}
