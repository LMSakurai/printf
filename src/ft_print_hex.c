/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:00:18 by lmasato-          #+#    #+#             */
/*   Updated: 2022/10/01 03:26:32 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_size(unsigned int n);

int	ft_print_hex(unsigned int n, char c, int r)
{
	char	*base;
	char	*hex;
	int		count;
	int		hex_size;

	count = 0;
	hex_size = ft_hex_size(n);
	if (n == 0)
		return (ft_print_char('0'));
	if (c == 'x')
		base = ft_strdup("0123456789abcdef");
	else
		base = ft_strdup("0123456789ABCDEF");
	hex = malloc(sizeof(char) * (hex_size + 1));
	while (n > 0)
	{
		r = n % 16;
		n = n / 16;
		hex[hex_size - count - 1] = base[r];
		count++;
	}
	write(1, hex, hex_size);
	free(base);
	free(hex);
	return (count);
}

static int	ft_hex_size(unsigned int n)
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
