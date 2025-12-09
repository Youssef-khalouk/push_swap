/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:17:41 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/10/30 11:02:38 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	if (!s || fd < 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (write(fd, s, i));
}
