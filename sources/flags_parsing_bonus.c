/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:04:43 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/23 17:42:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	width_is(const char *input, int index, int size)
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

int	count_number(t_toprint *tab, const char *input, int i)
{
	int	count;

	count = 0;
	while (input[i] && ft_isdigit(input[i]))
	{
		count++;
		i++;
	}
	if (count)
		tab->width = width_is(input, i, count);
	return (i);
}

int	def_flags(t_toprint *tab, const char *input, int i)
{
	char	*nbr;

	// FLAGS
	if (input[i] && (input[i] >= '1' && input[i] <= '9'))
		i = count_number(tab, input, i);
	while (input[i] == '-' || input[i] == '0' || input[i] == '.')
	{
		if (input[i] == '0')
			tab->pad_zero = 1;
		else if (input[i] == '-')
		{
			tab->justify = 1;
			tab->pad_zero = 0;
		}
		else if (input[i] == '.')
			tab->precision = 1;
		i++;
	}
	if (!tab->width && input[i] && ft_isdigit(input[i]))
		i = count_number(tab, input, i);
	return (i);
}
