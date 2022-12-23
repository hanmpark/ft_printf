/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:33:23 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/23 17:48:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_toprint
{
	va_list	args;
	int		len;
	int		justify;
	int		width;
	int		pad_zero;
	int		precision;
	int		count;
}	t_toprint;

int	ft_printf(const char *input, ...);
// TYPE_STDOUT
void	ft_printchar(t_toprint *tab, int is_char);
void	ft_putnbrbase(t_toprint *tab, char *base, long long i);
void	ft_putnbrbase_p(t_toprint *tab, char *base, unsigned long long i);
// FLAGS_PARSING
int		def_flags(t_toprint *tab, const char *input, int i);

#endif