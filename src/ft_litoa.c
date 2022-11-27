/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:52:38 by lmasato-          #+#    #+#             */
/*   Updated: 2022/10/01 04:57:18 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_long_len(long int n);
static void	ft_long_to_string(long n, char *p);
static char	*ft_edge_cases(void);

char	*ft_litoa(long int n)
{	
	char	*p;
	int		sign;

	sign = 0;
	if (n == 0)
		return (ft_edge_cases());
	if (n < 0)
	{	
		sign = 1;
		n = n * (-1);
	}
	p = malloc(sizeof(char) * (ft_long_len(n) + 1 + sign));
	if (sign == 1)
	{
		p[0] = '-';
		ft_long_to_string(n, &p[1]);
	}
	else
		ft_long_to_string(n, p);
	return (p);
}

static int	ft_long_len(long int n)
{	
	int	count;

	count = 0;
	if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_long_to_string(long int n, char *p)
{	
	int	r;
	int	i;
	int	size;

	size = ft_long_len(n) - 1;
	i = size;
	while (n > 0)
	{	
		r = n % 10;
		n = n / 10;
		p[i] = r + '0';
		i--;
	}
	p[size + 1] = '\0';
}

static char	*ft_edge_cases(void)
{	
	char	*p;

	p = malloc(sizeof(char) * 2);
	p[0] = '0';
	p[1] = '\0';
	return (p);
}
