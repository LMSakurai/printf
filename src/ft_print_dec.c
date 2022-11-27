/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:59:56 by lmasato-          #+#    #+#             */
/*   Updated: 2022/10/01 02:58:00 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(signed long int n)
{	
	int		size;
	char	*s;

	s = ft_litoa(n);
	size = ft_strlen(s);
	write(1, s, size);
	free(s);
	return (size);
}
