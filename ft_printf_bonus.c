/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:34 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/23 17:36:36 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

t_toprint	*init_tab(t_toprint *tab)
{
	tab->len = 0;
	tab->justify = 0;
	tab->width = 0;
	tab->pad_zero = 0;
	tab->precision = 0;
	return (tab);
}

void	def_numbers(t_toprint *tab, const char *input, unsigned long long i)
{
	if (input[i] && (input[i] == 'd' || input[i] == 'i'))
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
		ft_putnbrbase_p(tab, "0123456789abcdef", va_arg(tab->args, unsigned long long));
	}
}

int	def_types(t_toprint *tab, const char *input, unsigned long long i)
{
	char	c;

	while (input[i] && input[i] == ' ')
		i++;
	i = def_flags(tab, input, i);
	c = input[i];
	if (input[i] && (c == 'd' || c == 'i' || c == 'u' || c == 'x' ||
		c =='X' || c == 'p'))
		def_numbers(tab, input, i);
	else if (input[i] && c == 'c')
		ft_printchar(tab, 1);
	else if (input[i] && c == 's')
		ft_printchar(tab, 0);
	else if (input[i] && c == '%')
		tab->len += write(1, "%", 1);
	else
		tab->len += write(1, &input[i], 1);
	return (i);
}

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
			i = def_types(tab, input, i + 1);
		else if (input[i] && input[i] != '%')
			cnbr += write(1, &input[i], 1);
		i++;
	}
	va_end(tab->args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}
