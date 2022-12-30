/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:34 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/30 17:48:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
/*
t_printer	*init_printertab(void)
{
	t_printer	*printer_tab;
	char		*str;
	int			i;

	printer_tab = malloc(3 * sizeof(t_printer));
	if (!printer_tab)
		return (0);
	str = "cspdiuxX";
	i = 0;
	while (i < 8)
	{
		printer_tab[i].c = str[i];
		i++;
	}
	printer_tab[0].ft = &print_c;
	printer_tab[1].ft = &print_str;
}
*/
void	def_types(t_parseflags *tab, const char *input, int *i)
{
	char			c;
	int				k;
	const t_printer	printer_tab[] = {{'s', &print_str}, {'c', &print_c},
	{'d', &print_decimal}, {'i', &print_decimal}, {'u', &print_unsigned},
	};

	(*i)++;
	while (input[*i] && input[*i] == ' ')
		(*i)++;
	def_flags(tab, input, i);
	c = input[*i];
	k = -1;
	while (++k < 5)
	{
		if (c == printer_tab[k].c)
		{
			printer_tab[k].ft(tab);
			return ;
		}
	}
}

int	ft_printf(const char *input, ...)
{
	t_parseflags	*tab;
	int				i;
	int				cnbr;

	tab = malloc(sizeof(t_parseflags));
	if (!tab)
		return (-1);
	tab->len = 0;
	va_start(tab->args, input);
	i = 0;
	cnbr = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
			def_types(tab, input, &i);
		else if (input[i] && input[i] != '%')
			cnbr += write(1, &input[i], 1);
		i++;
	}
	va_end(tab->args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}
