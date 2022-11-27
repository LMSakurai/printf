/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:00:31 by lmasato-          #+#    #+#             */
/*   Updated: 2022/10/01 03:10:59 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *s)
{	
	size_t	size;

	if (s == NULL)
	{	
		write(1, "(null)", 6);
		return (6);
	}
	size = ft_strlen(s);
	write(1, s, size);
	return (size);
}
