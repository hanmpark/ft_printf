/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:39:35 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/21 23:59:07 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_toprint	*init_tab(t_toprint *tab)
{
	tab->len = 0;
	tab->left_justify = 0;
	tab->width = 0;
	tab->pad_zero = 0;
	tab->precision = 0;
	return (tab);
}

int	def_input(t_toprint *tab, const char *input, unsigned long long i)
{
	while (input[i] && input[i] == ' ')
		i++;
	if (input[i] && input[i] == 'c')
		ft_putchar_input(tab);
	else if (input[i] && input[i] == 's')
		ft_putstr_input(tab);
	else if (input[i] && (input[i] == 'd' || input[i] == 'i'))
		ft_putnbrbase(tab, "0123456789", va_arg(tab->args, int));
	else if (input[i] && input[i] == 'u')
		ft_putnbrbase(tab, "0123456789", va_arg(tab->args, unsigned));
	else if (input[i] && input[i] == 'x')
		ft_putnbrbase(tab, "0123456789abcdef", va_arg(tab->args, unsigned));
	else if (input[i] && input[i] == 'X')
		ft_putnbrbase(tab, "0123456789ABCDEF", va_arg(tab->args, unsigned));
	else if (input[i] && input[i] == 'p')
	{
		tab->len += write(1, "0x", 2);
		ft_putnbrbase_p(tab, "0123456789abcdef",
			va_arg(tab->args, unsigned long long));
	}
	else if (input[i] && input[i] == '%')
		tab->len += write(1, "%", 1);
	else
		tab->len += write(1, &input[i], 1);
	return (i);
}
#include <stdio.h>
int	ft_printf(const char *input, ...)
{
	t_toprint	*tab;
	int			i;
	int			cnbr;

	tab = malloc(sizeof(t_toprint));
	if (!tab)
		return (-1);
	init_tab(tab);
	va_start(tab->args, input);
	i = 0;
	cnbr = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i = def_flags(tab, input, i + 1);
			i = def_input(tab, input, i);
		}
		else if (input[i] && input[i] != '%')
			cnbr += write(1, &input[i], 1);
		i++;
	}
	va_end(tab->args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}
