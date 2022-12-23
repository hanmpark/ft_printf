/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_stdout_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:40:18 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/24 00:07:29 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	count_nbr(int n)
{
	int					count;
	unsigned long long	multiplier;

	count = 0;
	multiplier = 1;
	while (n / multiplier)
	{
		count++;
		multiplier *= 10;
	}
	return (count);
}

void	ft_putnbr(t_toprint *tab, int n)
{
	int	len_nbr;

	if (n < 0)
	{
		len_nbr++;
		n *= -1;
	}
	len_nbr = count_nbr(n);
	while (len_nbr--)
	{
		tab->len += write(1, n % 10 + '0', 1);
		n /= 10;
	}
}