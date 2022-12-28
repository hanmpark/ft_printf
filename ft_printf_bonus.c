/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:34 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 02:18:10 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

void	def_types(t_parseflags *tab, const char *input, int *i)
{
	t_printer	printer_tab[1] = {{'s', &print_str}};
	char		c;
	int			k;

	while (input[*i] && input[*i] == ' ')
		(*i)++;
	def_flags(tab, input, i);
	c = input[*i];
	k = 0;
	while (k < 1)
	{
		if (c == printer_tab[k].c)
		{
			printer_tab[k].ft(tab);
			return ;
		}
		k++;
	}
}

int	ft_printf(const char *input, ...)
{
	t_parseflags	*tab;
	int				*i;
	int				cnbr;

	tab = malloc(sizeof(t_parseflags));
	if (!tab)
		return (-1);
	va_start(tab->args, input);
	i = 0;
	cnbr = 0;
	while (input[*i])
	{
		if (input[*i] == '%' && input[*i + 1])
			def_types(tab, input, i + 1);
		else if (input[*i] && input[*i] != '%')
			cnbr += write(1, &input[*i], 1);
		(*i)++;
	}
	va_end(tab->args);
	cnbr += tab->len;
	free(tab);
	return (cnbr);
}
