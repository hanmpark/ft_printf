/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:28:36 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/25 20:33:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbrbase(t_toprint *tab, char *base, long long i)
{
	char				*str;
	size_t				baselen;

	baselen = ft_strlen(base);
	if (i < 0)
	{
		ft_putchar_fd('-', 1);
		i *= -1;
	}
	if (i > baselen)
		ft_putnbrbase(tab, base, i / baselen);
	ft_putchar_fd(base[i % baselen], 1);
	tab->len++;
}

void	ft_putnbrbase_p(t_toprint *tab, char *base, unsigned long long i)
{
	char				*str;
	size_t				baselen;

	baselen = ft_strlen(base);
	if (i > baselen)
		ft_putnbrbase_p(tab, base, i / baselen);
	ft_putchar_fd(base[i % baselen], 1);
	tab->len++;
}