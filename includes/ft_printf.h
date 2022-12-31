/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:33:23 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/31 17:38:18 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# define TRUE 1
# define FALSE 0

typedef struct s_parseflags
{
	va_list	args;
	int		len;
	int		check_width;
	int		check_precision;
	char	check_nbrflags;
	char	check_zerojustify;
	int		width;
	int		precision;
}	t_parseflags;

typedef void	(*t_ftprinter)(t_parseflags *);
typedef struct s_printer
{
	char		c;
	t_ftprinter	ft;
}	t_printer;

int		ft_printf(const char *input, ...);
// PRINT
void	print_str(t_parseflags *tab);
void	print_c(t_parseflags *tab);
void	print_decimal(t_parseflags *tab);
void	print_unsigned(t_parseflags *tab);
void	print_x(t_parseflags *tab);
void	print_xx(t_parseflags *tab);
// FLAGS
void	def_flags(t_parseflags *tab, const char *input, int *i);
// TREAT_FLAGS
void	str_wflags(t_parseflags *tab, char *str, size_t len);
void	nbr_wflags(t_parseflags *tab, char *str, int sign);
void	width(t_parseflags *tab, size_t len);

#endif