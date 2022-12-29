/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:04:43 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/29 18:18:18 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	init_flags(t_parseflags *tab)
{
	tab->check_width = 0;
	tab->check_precision = 0;
	tab->check_nbrflags = 0;
	tab->check_zerojustify = 0;
	tab->width = 0;
	tab->precision = 0;
}

void	parse_width(t_parseflags *tab, const char *input, int *i)
{
	if (input[*i] && ft_isdigit(input[*i]))
	{
		tab->check_width = TRUE;
		tab->width = ft_atoi(input + *i);
	}
	while (input[*i] && (ft_isdigit(input[*i])))
		(*i)++;
}

void	parse_precision(t_parseflags *tab, const char *input, int *i)
{
	if (input[*i] && input[*i] == '.')
	{
		tab->check_precision = TRUE;
		(*i)++;
		if (input[*i] && ft_isdigit(input[*i]))
			tab->precision = ft_atoi(input + *i);
		while (input[*i] && ft_isdigit(input[*i]))
			(*i)++;
	}
}

void	parse_flags(t_parseflags *tab, const char *input, int *i)
{
	while (input[*i] && (input[*i] == '#' || input[*i] == ' '
			|| input[*i] == '+'))
	{
		tab->check_nbrflags = input[*i];
		(*i)++;
	}
	while (input[*i] && (input[*i] == '-' || input[*i] == '0'))
	{
		if (tab->check_zerojustify != '-')
			tab->check_zerojustify = input[*i];
		(*i)++;
	}
}

void	def_flags(t_parseflags *tab, const char *input, int *i)
{
	init_flags(tab);
	parse_flags(tab, input, i);
	parse_width(tab, input, i);
	parse_precision(tab, input, i);
}
