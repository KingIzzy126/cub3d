/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:11:41 by ialashqa          #+#    #+#             */
/*   Updated: 2024/04/30 14:25:10 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_printfstr("-2147483648"));
	}
	else if (n < 0)
	{
		count += ft_printfchar('-');
		n = -n;
	}
	else if (n == 0)
	{
		return (ft_printfchar('0'));
	}
	if (n >= 10)
	{
		count += ft_printfint(n / 10);
	}
	count += ft_printfchar((n % 10) + '0');
	return (count);
}
