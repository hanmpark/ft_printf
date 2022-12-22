/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:52:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/22 12:10:12 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_toprint
{
	va_list	args;
	int		len;
	int		left_justify;
	int		width;
	int		pad_zero;
	int		precision;
}	t_toprint;

int		ft_printf(const char *input, ...);
// TYPE_STDOUT
void	ft_putchar_input(t_toprint *tab);
void	ft_putstr_input(t_toprint *tab);
void	ft_putnbr_decibase(t_toprint *tab, long long i);
void	ft_putnbr_hexabase(t_toprint *tab, unsigned long long i, int is_maj);
// FLAGS_PARSING
int		def_flags(t_toprint *tab, const char *input, int i);
int		count_number(t_toprint *tab, const char *input, int i);
// TREAT_FLAGS
int		treat_flags(t_toprint *tab, char *str);
void	reset_flags(t_toprint *tab);

#endif