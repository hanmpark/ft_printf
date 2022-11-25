/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:41:09 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/17 14:34:02 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*char	check_char(unsigned int i, char c)
{
	char	newc;
	
	newc = (unsigned int)c + i;
	return (newc);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nstr;

	if (!s)
		return (0);
	nstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = 0;
	return (nstr);
}
/*#include <stdio.h>
int	main()
{
	printf("%s\n", ft_strmapi("abcdef", check_char));
	return (0);
}*/