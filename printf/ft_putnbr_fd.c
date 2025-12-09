/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:29:13 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/10/29 18:54:02 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr(unsigned int n, int fd, int *count)
{
	char	tmp;

	if (n >= 10)
		ft_putnbr(n / 10, fd, count);
	tmp = (n % 10) + '0';
	(*count) += write(fd, &tmp, 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (fd < 0)
		return (0);
	if (n < 0)
	{
		count += write(fd, "-", 1);
		ft_putnbr((unsigned int)(-(long)n), fd, &count);
	}
	else
		ft_putnbr((unsigned int)n, fd, &count);
	return (count);
}
