/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:13:49 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/08 17:13:51 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_future_len(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int		f_10(int n)
{
	int res;

	res = 1;
	while (n > 0)
	{
		res = res * 10;
		n--;
	}
	return (res);
}

static char		*ft_itoanull(int n, char *fresh)
{
	if (fresh == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(fresh, "-2147483648"));
	else
		return (ft_strcpy(fresh, "0"));
}

char			*ft_itoa(int n)
{
	char	*fresh;
	int		len;
	int		i;

	i = 0;
	len = count_future_len(n);
	fresh = ft_strnew(len);
	if (fresh == NULL || n == -2147483648 || n == -0)
		return (ft_itoanull(n, fresh));
	if (n < 0 && len--)
	{
		fresh[i] = '-';
		i++;
		n = -1 * n;
	}
	while (len > 0)
	{
		fresh[i] = (n / f_10(len - 1)) + 48;
		n = n - ((n / f_10(len - 1)) * f_10(len - 1));
		len--;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
