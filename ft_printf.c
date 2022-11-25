/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:39:35 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/25 21:42:10 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_toprint	*init_tab(t_toprint *tab)
{
	tab->len = 0;
	return (tab);
}

int	def_input(t_toprint *tab, const char *input, int i)
{
	if (input[i] && input[i] == 'c')
		ft_putchar_f(tab);
	else if (input[i] && input[i] == 's')
		ft_putstr_f(tab);
	else if (input[i] && (input[i] == 'd' || input[i] == 'i'))
		ft_putnbrbase(tab, "0123456789", va_arg(tab->args, int));
	else if (input[i] && input[i] == 'u')
		ft_putnbrbase(tab, "0123456789", va_arg(tab->args, unsigned int));
	else if (input[i] && input[i] == 'x')
		ft_putnbrbase(tab, "0123456789abcdef", va_arg(tab->args, unsigned int));
	else if (input[i] && input[i] == 'X')
		ft_putnbrbase(tab, "0123456789ABCDEF", va_arg(tab->args, unsigned int));
	else if (input[i] && input[i] == 'p')
	{
		tab->len += write(1, "0x", 2);
		ft_putnbrbase_p(tab, "0123456789abcdef", va_arg(tab->args, unsigned long long));
	}
	else if (input[i] && input[i] == '%')
		tab->len += write(1, "%", 1);
	else if (input[i])
		tab->len += write(1, &input[i], 1);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	t_toprint				*tab;
	unsigned long long int	i;
	unsigned long long int	cnbr;

	tab = malloc(sizeof(t_toprint));
	if (!tab)
		return (0);
	init_tab(tab);
	va_start(tab->args, input);
	i = -1;
	cnbr = 0;
	while (input[++i])
	{
		if (input[i] == '%')
			i = def_input(tab, input, i + 1);
		else
			cnbr += write(1, &input[i], 1);
	}
	va_end(tab->args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}
// ofeEgGn