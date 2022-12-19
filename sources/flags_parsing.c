/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:04:43 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/19 19:12:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	set_width(char *input, int index, int size)
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

int	def_flags(t_toprint *tab, const char *input, int i)
{
	int	count;

	count = 0;
	// FLAGS
	if (input[i] && (input[i] >= '1' && input[i] <= '9'))
	{
		while (input[i] && (input[i] >= '1' && input[i] <= '9'))
		{
			count++;
			i++;
		}
	}
	else if (input[i] == '-')
		tab->left_justify = 1;
	else if (input[i] == '0')
		tab->pad_zero = 1;
	else if (input[i] == '.')
		tab->precision = 1;
	i++;
	while (input[i] && (input[i] >= '1' && input[i] <= '9'))
	{
		count++;
		i++;
	}
	// WIDTH FOR FLAGS
	if (count > 0)
		tab->width = set_width((char *)input, i, count);
	return (i);
}
