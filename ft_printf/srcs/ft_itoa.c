/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:43:56 by dangonza          #+#    #+#             */
/*   Updated: 2022/02/02 17:19:28 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static size_t	ft_numlen(long long int n, int base_len)
{
	size_t	n_len;

	if (!n)
		return (1);
	n_len = 0;
	if (n < 0)
		n_len++;
	while (n != 0)
	{
		n_len++;
		n /= base_len;
	}
	return (n_len);
}

char	*ft_itoa(long long int n, char *base, int base_len)
{
	size_t	n_len;
	int		last_dig;
	char	*str;

	n_len = ft_numlen(n, base_len);
	str = malloc(sizeof(char) * (n_len + 1));
	if (str == NULL)
		return (str);
	*(str + n_len) = '\0';
	if (n < 0)
		*str = '-';
	if (n == 0)
		*(str + (--n_len)) = '0';
	while (n != 0)
	{
		last_dig = n % base_len;
		if (last_dig < 0)
			last_dig = -(last_dig);
		*(str + (--n_len)) = *(base + last_dig);
		n /= base_len;
	}
	return (str);
}
