/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:46:00 by ialashqa          #+#    #+#             */
/*   Updated: 2024/04/30 14:25:01 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (ft_printfstr("(null)"));
	}
	while (*str != '\0')
	{
		ft_printfchar((int)*str);
		str++;
		i++;
	}
	return (i);
}
