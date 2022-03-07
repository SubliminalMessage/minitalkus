/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:59:09 by dangonza          #+#    #+#             */
/*   Updated: 2022/02/14 13:59:13 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_uppercase(char *s)
{
	int	index;

	index = 0;
	while (*(s + index))
	{
		if (*(s + index) >= 97 && *(s + index) <= 122)
			*(s + index) -= 32;
		index++;
	}
	return (s);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
