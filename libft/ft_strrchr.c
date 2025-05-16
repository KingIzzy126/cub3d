/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:30:05 by ialashqa          #+#    #+#             */
/*   Updated: 2023/11/19 14:24:08 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (s == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char )c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (0);
}
