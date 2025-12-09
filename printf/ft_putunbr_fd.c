/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:29:13 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/10/29 18:24:54 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putunbr(unsigned int n, int fd, int *count)
{
	char	tmp;

	if (n >= 10)
		ft_putunbr(n / 10, fd, count);
	tmp = (n % 10) + '0';
	write(fd, &tmp, 1);
	(*count)++;
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (fd < 0)
		return (0);
	ft_putunbr(n, fd, &count);
	return (count);
}
