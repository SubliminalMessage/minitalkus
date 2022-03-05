/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:27:00 by dangonza          #+#    #+#             */
/*   Updated: 2022/02/02 17:19:49 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
	i			=>	index
	last_prtd	=>	last_printed
*/
int	ft_printf(const char *str, ...)
{
	va_list	vlist;
	int		i;
	int		last_prtd;
	int		total;

	va_start(vlist, str);
	i = 0;
	last_prtd = 0;
	total = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%')
		{
			total += write(1, (str + last_prtd), ((i - 1) - (last_prtd - 1)));
			last_prtd = i;
			total += print_special(vlist, str + i, &last_prtd);
			i = last_prtd;
			continue ;
		}
		i++;
	}
	total += write(1, (str + last_prtd), ((i - 1) - (last_prtd - 1)));
	va_end(vlist);
	return (total);
}

int	print_special(va_list vlist, const char *str, int *last_printed)
{
	int	count;

	str++;
	count = 0;
	*last_printed += 2;
	if (*str == 'd' || *str == 'i')
		count = print_base10((long int) va_arg(vlist, int));
	if (*str == 'u')
		count = print_base10((long int) va_arg(vlist, unsigned int));
	if (*str == 'c')
		count = ft_putchar_fd(va_arg(vlist, int), 1);
	if (*str == 's')
		count = ft_putstr_fd(va_arg(vlist, char *), 1);
	if (*str == 'x')
		count = print_base16((long int) va_arg(vlist, unsigned int), 0);
	if (*str == 'X')
		count = print_base16((long int) va_arg(vlist, unsigned int), 1);
	if (*str == 'p')
		count = print_pointer(va_arg(vlist, unsigned long));
	if (*str == '%')
		count = ft_putchar_fd('%', 1);
	return (count);
}
