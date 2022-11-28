/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:52:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/28 08:32:00 by hanmpark         ###   ########.fr       */
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
}	t_toprint;

int		ft_printf(const char *input, ...);
void	ft_putchar_f(t_toprint *tab);
void	ft_putstr_f(t_toprint *tab);
void	ft_putnbrbase(t_toprint *tab, char *base, long long i);
void	ft_putnbrbase_p(t_toprint *tab, char *base, unsigned long i);

#endif