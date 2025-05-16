/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfunit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:04:22 by ismailalash       #+#    #+#             */
/*   Updated: 2024/04/30 14:24:50 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfunit(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_printfunit(n / 10);
	}
	i += ft_printfchar((n % 10) + '0');
	return (i);
}
