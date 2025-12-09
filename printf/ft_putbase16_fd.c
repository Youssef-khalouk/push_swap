/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase16_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:29:13 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/10/30 11:15:02 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putbase(unsigned int n, int fd, char *base16, int *count)
{
	if (n >= 16)
		ft_putbase(n / 16, fd, base16, count);
	(*count) += write(fd, &base16[n % 16], 1);
}

int	ft_putbase16_fd(unsigned int n, int fd, char isup)
{
	int		count;
	char	*base16;

	if (isup)
		base16 = "0123456789ABCDEF";
	else
		base16 = "0123456789abcdef";
	count = 0;
	if (fd < 0)
		return (0);
	ft_putbase(n, fd, base16, &count);
	return (count);
}
