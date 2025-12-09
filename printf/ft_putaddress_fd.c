/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:29:13 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/10/30 11:06:13 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putbase(unsigned long long n, int fd, char *base16, int *count)
{
	if (n >= 16)
		ft_putbase(n / 16, fd, base16, count);
	(*count) += write(fd, &base16[n % 16], 1);
}

int	ft_putaddress_fd(void *p, int fd)
{
	int					count;
	unsigned long long	pnumber;
	char				*base16;

	base16 = "0123456789abcdef";
	pnumber = (unsigned long long)p;
	count = 0;
	if (fd < 0)
		return (0);
	if (pnumber == 0)
		return (write(fd, "(nil)", 5));
	count += write(fd, "0x", 2);
	ft_putbase(pnumber, fd, base16, &count);
	return (count);
}
