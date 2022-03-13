/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasson <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:24:46 by lomasson          #+#    #+#             */
/*   Updated: 2022/03/13 22:20:22 by lomasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_fonctions(char c, va_list *ap)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_print_c(va_arg(*ap, int));
	else if (c == 's')
		count = ft_print_s(va_arg(*ap, char *));
	else if (c == 'p')
		count = ft_print_ptr(va_arg(*ap, unsigned long int), 3, count);
	else if (c == 'd')
		count = ft_print_num(va_arg(*ap, int), count);
	else if (c == 'i')
		count = ft_print_num(va_arg(*ap, int), count);
	else if (c == 'u')
		count = ft_print_u(va_arg(*ap, unsigned int), count);
	else if (c == '%')
		count = write(1, "%", 1);
	else if (c == 'x')
		count = ft_print_hexa(va_arg(*ap, unsigned int), 0, count);
	else if (c == 'X')
		count = ft_print_hexa(va_arg(*ap, long int), 1, count);
	return (count);
}

int ft_printf(const char *str, ...)
{
	int	i;
	int	j;
	va_list	ap;
	char *fonctions;
	int count;

	fonctions = "cspdiu%xX";
	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = -1;
			while (fonctions[++j] && str[i + 1])
			{
				if (str[i + 1] == fonctions[j])
				{
					i++;
					count += ft_printf_fonctions(str[i++], &ap);
					break;
				}
			}
		}
		else
			count += write(1, &str[i++], 1);
	}
	va_end(ap);
	return (count);
}
