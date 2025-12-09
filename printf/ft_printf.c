/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:39:01 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/10/30 10:47:36 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_putparameter(unsigned char c, va_list *args, char *wrong)
{
	if (c == '\0')
	{
		*wrong = 1;
		return (0);
	}
	else if (c == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	else if (c == 'u')
		return (ft_putunbr_fd(va_arg(*args, unsigned int), 1));
	else if (c == 'x' || c == 'X')
		return (ft_putbase16_fd(va_arg(*args, int), 1, c == 'X'));
	else if (c == 'p')
		return (ft_putaddress_fd(va_arg(*args, void *), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	write(1, "%", 1);
	write(1, &c, 1);
	*wrong = 1;
	return (2);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	wrong;

	wrong = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_putparameter(*(++format), &args, &wrong);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	if (wrong)
		return (-1);
	return (count);
}
