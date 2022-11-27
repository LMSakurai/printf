/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:00:25 by lmasato-          #+#    #+#             */
/*   Updated: 2022/10/01 03:08:13 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_long_size(unsigned long n);
static int	ft_long_to_hex(unsigned long n);

int	ft_print_pointer(unsigned long int p)
{	
	int	size;

	if (p == 0)
	{	
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	size = ft_long_to_hex(p);
	return (size + 2);
}

static int	ft_long_to_hex(unsigned long n)
{
	char	*base;
	char	*hex;
	int		i;
	int		count;
	int		hex_size;

	count = 0;
	hex_size = ft_long_size(n);
	if (n == 0)
		return (ft_print_char('0'));
	base = ft_strdup("0123456789abcdef");
	hex = malloc(sizeof(char) * (hex_size + 1));
	while (n > 0)
	{
		i = n % 16;
		n = n / 16;
		hex[hex_size - count - 1] = base[i];
		count++;
	}
	write(1, hex, hex_size);
	free(base);
	free(hex);
	return (count);
}

static int	ft_long_size(unsigned long n)
{	
	int	i;
	int	count;

	count = 0;
	while (n > 0)
	{
		i = n % 16;
		n = n / 16;
		count++;
	}
	return (count);
}
