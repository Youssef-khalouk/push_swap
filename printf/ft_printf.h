/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:41:04 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/10/30 11:15:47 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putstr_fd(char *s, int fd);

int	ft_putnbr_fd(int n, int fd);

int	ft_putchar_fd(char c, int fd);

int	ft_putunbr_fd(unsigned int n, int fd);

int	ft_putbase16_fd(unsigned int n, int fd, char isup);

int	ft_putaddress_fd(void *p, int fd);

#endif