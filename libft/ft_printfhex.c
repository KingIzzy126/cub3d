/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:32 by ialashqa          #+#    #+#             */
/*   Updated: 2024/04/30 14:25:11 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfhex(unsigned int n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_printfhex(n / 16, base);
	}
	i += ft_printfchar(base[n % 16]);
	return (i);
}
