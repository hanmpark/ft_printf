/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:04:43 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/23 23:35:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	nbr_is(const char *input, int index, int size)
{
	char	*nbr;
	int		i;
	int		res;

	nbr = malloc((size + 1) * sizeof(char));
	i = 0;
	while (input[index - size + i])
	{
		nbr[i] = input[index - size + i];
		i++;
	}
	nbr[i] = 0;
	res = ft_atoi(nbr);
	free(nbr);
	return (res);
}

int	set_width(t_toprint *tab, const char *input, int i)
{
	int	count;

	count = 0;
	while (input[i] && ft_isdigit(input[i]))
	{
		count++;
		i++;
	}
	if (count)
		tab->width = nbr_is(input, i, count);
	return (i);
}

int	pad_zero_is(t_toprint *tab, char *input, int i)
{
	int	count;

	count = 0;
	while (input[i] && ft_isdigit(input[i]))
	{
		count++;
		i++;
	}
	if (count)
		tab->pad_zero = nbr_is(input, i, count);
	return (i);
}

int	justify_is(t_toprint *tab, char *input, int i)
{
	int	count;

	count = 0;
	while (input[i] && ft_isdigit(input[i]))
	{
		count++;
		i++;
	}
	if (count)
		tab->justify = nbr_is(input, i, count);
	return (i);
}

int	precision_is(t_toprint *tab, char *input, int i)
{
	int	count;

	count = 0;
	while (input[i] && ft_isdigit(input[i]))
	{
		count++;
		i++;
	}
	if (count)
		tab->precision = nbr_is(input, i, count);
	return (i);
}

int	def_flags(t_toprint *tab, const char *input, int i)
{
	char	*nbr;

	// FLAGS
	if (input[i] && (input[i] >= '1' && input[i] <= '9'))
		i = set_width(tab, input, i);
	while (input[i] && (input[i] == '0' || input[i] == '-' || input[i] == '.'))
	{
		if (input[i] == '0' && !tab->justify)
			i = pad_zero_is(tab, input, i);
		else if (input[i] == '-')
			i = justify_is(tab, input, i);
		else if (input[i] == '.')
			i = precision_is(tab, input, i);
	}
	if (!tab->width && input[i] && ft_isdigit(input[i]))
		i = set_width(tab, input, i);
	return (i);
}
