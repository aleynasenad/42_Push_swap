/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:33:35 by aldurmaz          #+#    #+#             */
/*   Updated: 2024/12/01 14:05:01 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check2(char c, va_list arg)
{
	int				p;
	unsigned long	ptr;

	(void)c;
	ptr = va_arg(arg, unsigned long);
	p = 0;
	if (ptr == (unsigned long) NULL)
		p += ft_putstr("(nil)");
	else
	{
		p += ft_putstr("0x");
		p += ft_pointer(ptr);
	}
	return (p);
}

int	ft_check(char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count += ft_unsign(va_arg(arg, unsigned int));
	else if (c == 'p')
	{
		count += ft_check2(c, arg);
	}
	else if (c == 'x')
		count += ft_hex(va_arg(arg, int), 0);
	else if (c == 'X')
		count += ft_hex(va_arg(arg, int), 1);
	else if (c == '%')
		count += ft_putchar('%');
	else
		return (ft_putchar(c));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		check;

	va_start (arg, str);
	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			check++;
		}
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			check += ft_check(str[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (check);
}
