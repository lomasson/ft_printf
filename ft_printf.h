/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasson <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:45:46 by lomasson          #+#    #+#             */
/*   Updated: 2022/03/14 13:27:54 by lomasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_s(char *str);
int	ft_print_hexa(unsigned int nb, int u, int count);
int	ft_print_num(long int n, int count);
int	ft_print_u(unsigned int n, int count);
int	ft_print_ptr(unsigned long int n, int u, int count);
#endif
