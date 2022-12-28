/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:33:23 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 01:43:45 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../libft/libft.h"
# include <stdarg.h>
# define TRUE 1
# define FALSE 0

typedef struct s_parseflags
{
	va_list	args;
	int		len;
	int		check_hash;
	int		check_width;
	int		check_sign;
	int		check_space;
	int		check_precision;
	char	check_zerojustify;
	int		width;
	int		precision;
}	t_parseflags;

typedef void (*print_arg)(t_parseflags *);

typedef struct s_printer
{
	char		c;
	print_arg	ft;
}	t_printer;

int		ft_printf(const char *input, ...);
// PRINT_BONUS
void	print_str(t_parseflags *tab);
// FLAGS_BONUS
void	def_flags(t_parseflags *tab, const char *input, int *i);

#endif