/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:28:36 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/27 21:09:52 by hanmpark         ###   ########.fr       */
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
		tab->len += write(1, "-", 1);
		i *= -1;
	}
	if (i >= baselen)
		ft_putnbrbase(tab, base, i / baselen);
	ft_putchar_fd(base[i % baselen], 1);
	tab->len++;
}

void	ft_putnbrbase_p(t_toprint *tab, char *base, unsigned long i)
{
	char				*str;
	size_t				baselen;

	baselen = ft_strlen(base);
	if (i >= baselen)
		ft_putnbrbase_p(tab, base, i / baselen);
	ft_putchar_fd(base[i % baselen], 1);
	tab->len++;
}
