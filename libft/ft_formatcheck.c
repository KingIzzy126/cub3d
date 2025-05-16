/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:56 by ialashqa          #+#    #+#             */
/*   Updated: 2024/04/30 14:26:18 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formatcheck(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_printfchar(va_arg(args, int));
	else if (*format == 's')
		i += ft_printfstr(va_arg(args, char *));
	else if (*format == 'p')
		i += ft_printfpointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		i += ft_printfint(va_arg(args, int));
	else if (*format == 'u')
		i += ft_printfunit(va_arg(args, unsigned int));
	else if (*format == 'x')
		i += ft_printfhex(va_arg(args, int), LBASE);
	else if (*format == 'X')
		i += ft_printfhex(va_arg(args, int), UBASE);
	else if (*format == '%')
	{
		ft_printfchar('%');
		return (1);
	}
	return (i);
}
