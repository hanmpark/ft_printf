/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:04:43 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 02:23:12 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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

void	parse_flags(t_parseflags *tab, const char *input, int *i)
{
	while (input[*i] && (input[*i] == '-' || input[*i] == '0' || input[*i] == '+'))
	{
		if (tab->check_zerojustify != '-' && input[*i] != '+')
			tab->check_zerojustify = input[*i];
		else if (input[*i] == '+')
			tab->check_sign = TRUE;
		(*i)++;
		printf("yes\n");
	}
}

void	parse_precision(t_parseflags *tab, const char *input, int *i)
{
	if (input[*i] && input[*i] == '.')
	{
		tab->check_precision = TRUE;
		(*i)++;
		if (input[*i] && ft_isdigit(input[*i]))
			tab->precision = ft_atoi(input + *i);
	}
}

void	def_flags(t_parseflags *tab, const char *input, int *i)
{
	ft_memset(tab, 0, sizeof(t_parseflags));
	printf("%d\n", *i);
	parse_flags(tab, input, i);
	parse_width(tab, input, i);
	if (input[*i] && input[*i] == ' ')
	{
		tab->check_space = TRUE;
		(*i)++;
	}
	if (input[*i] && input[*i] == '#')
	{
		tab->check_hash = TRUE;
		(*i)++;
	}
	parse_precision(tab, input, i);
}
