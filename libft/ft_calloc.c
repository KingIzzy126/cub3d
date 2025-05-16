/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:13:29 by ialashqa          #+#    #+#             */
/*   Updated: 2023/12/03 20:02:17 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	length;

	length = count * size;
	ptr = malloc(length);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, length);
	return (ptr);
}
