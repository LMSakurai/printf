/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:00:41 by lmasato-          #+#    #+#             */
/*   Updated: 2022/10/01 03:36:02 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_types(char c, va_list ap);

int	ft_printf(const char *s, ...)
{	
	size_t	i;
	size_t	bsize;
	va_list	ap;

	va_start(ap, s);
	i = 0;
	bsize = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			bsize = bsize + write(1, &s[i], 1);
		else
		{	
			i++;
			bsize = bsize + ft_print_types(s[i], ap);
		}
		i++;
	}
	return (bsize);
}

static int	ft_print_types(char c, va_list ap)
{	
	int	count;

	count = 0;
	if (c == '%')
		count = count + ft_print_char('%');
	if (c == 'c')
		count = count + ft_print_char(va_arg(ap, int));
	if (c == 's')
		count = count + ft_print_string(va_arg(ap, char *));
	if (c == 'd' || c == 'i')
		count = count + ft_print_dec(va_arg(ap, int));
	if (c == 'u')
		count = count + ft_print_dec(va_arg(ap, unsigned int));
	if (c == 'p')
		count = count + ft_print_pointer(va_arg(ap, unsigned long));
	if (c == 'x' || c == 'X')
		count = count + ft_print_hex(va_arg(ap, unsigned long), c, 0);
	return (count);
}
