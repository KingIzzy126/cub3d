/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:34:41 by ialashqa          #+#    #+#             */
/*   Updated: 2024/04/30 14:25:07 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex(unsigned long long n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_hex(n / 16, base);
	}
	i += ft_printfchar(base[n % 16]);
	return (i);
}

int	ft_printfpointer(void *n)
{
	int	i;

	i = 0;
	i += ft_printfstr("0x");
	i += ft_hex((unsigned long long)n, LBASE);
	return (i);
}
