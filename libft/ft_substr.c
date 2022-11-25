/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:31:11 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/21 10:25:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	int		gap;

	if (!s)
		return (NULL);
	if (*s == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	gap = ft_strlen(s) - start;
	while ((size_t)gap > len)
		gap--;
	dest = ft_calloc(gap + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i + start < ft_strlen(s) && s[start + i] && i < gap)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "hola";
	char	*strsub;

	strsub = ft_substr(str, 2, 3);
	printf("%s\n", strsub);
	return (0);
}*/