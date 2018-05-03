/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:05:09 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/08 16:05:10 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*fresh;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if ((i - start < len) && ((fresh = ft_strnew(i - start)) == NULL))
		return (NULL);
	else
	{
		if ((fresh = ft_strnew((int)len)) == NULL)
			return (NULL);
	}
	i = 0;
	while (s[start] != '\0' && i < (int)len)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
