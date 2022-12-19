/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:52:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/19 19:08:55 by hanmpark         ###   ########.fr       */
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
void	ft_putchar_input(t_toprint *tab);
void	ft_putstr_input(t_toprint *tab);
void	ft_putnbrbase(t_toprint *tab, char *base, long long i);
void	ft_putnbrbase_p(t_toprint *tab, char *base, unsigned long i);

int		set_width(char *input, int index, int size);
int		def_flags(t_toprint *tab, const char *input, int i);
char	*treat_flags_char(t_toprint *tab, char *str, size_t len);

#endif