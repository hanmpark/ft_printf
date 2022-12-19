/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:14:55 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/19 19:11:29 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// FLAGS ARE : - 0 . WITH WIDTH FOR STRINGS
char	*treat_flags_char(t_toprint *tab, char *str, size_t len)
{
	char	*nstr;
	size_t	space_left;
	size_t	i;

	nstr = ft_calloc((tab->width + 1), sizeof(char));
	space_left = tab->width - len;
	i = 0;
	if (tab->left_justify)
	{
		ft_strlcat(nstr, str, len);
		while (len + i <= (size_t)tab->width)
			nstr[len + i++] = ' ';
	}
	else if (tab->pad_zero)
	{
		ft_memset(nstr, '0', space_left);
		ft_strlcat(nstr + space_left, str, len);
	}
	else if (tab->precision)
	{
		free(nstr);
		nstr = ft_substr(str, 0, tab->width);
	}
	return (nstr);
}