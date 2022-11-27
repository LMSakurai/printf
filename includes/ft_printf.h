/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:01:12 by lmasato-          #+#    #+#             */
/*   Updated: 2022/10/01 05:04:34 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_print_char(int c);
int		ft_print_string(char *s);
int		ft_print_dec(signed long int n);
char	*ft_litoa(long int n);
size_t	ft_strlen(const char *s);
int		ft_print_hex(unsigned int n, char c, int r);
int		ft_print_pointer(unsigned long int p);
int		ft_printf(const char *s, ...);
char	*ft_strdup(const char *src);

#endif 