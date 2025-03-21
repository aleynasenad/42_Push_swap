/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:40:17 by aldurmaz          #+#    #+#             */
/*   Updated: 2024/12/01 14:13:06 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsign(unsigned int u)
{
	int	i;

	i = 0;
	if (u < 10)
		i += ft_putchar(u + '0');
	else
	{
		i += ft_unsign(u / 10);
		i += ft_unsign(u % 10);
	}
	return (i);
}

int	ft_pointer(unsigned long p)
{
	int	i;

	i = 0;
	if (p >= 16)
		i += ft_pointer(p / 16);
	if ((p % 16) < 10)
		i += ft_putchar((p % 16) + '0');
	else
		i += ft_putchar((p % 16) + 87);
	return (i);
}

int	ft_hex(unsigned int x, int b)
{
	int	i;

	i = 0;
	if (x >= 16)
		i += ft_hex(x / 16, b);
	if ((x % 16) < 10)
		i += ft_putchar((x % 16) + '0');
	else
	{
		if (b == 0)
			i += ft_putchar((x % 16) + 87);
		else
			i += ft_putchar((x % 16) + 55);
	}
	return (i);
}
