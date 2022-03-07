/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <dangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:47:57 by dangonza          #+#    #+#             */
/*   Updated: 2022/02/16 16:43:31 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_base10(long int num)
{
	char	*result_itoa;
	int		char_count;

	result_itoa = ft_itoa(num, BASE_10, 10);
	char_count = ft_putstr_fd(result_itoa, 1);
	free(result_itoa);
	return (char_count);
}

int	print_base16(long int num, int is_uppercase)
{
	char	*result_itoa;
	int		char_count;

	result_itoa = ft_itoa(num, BASE_16, 16);
	if (is_uppercase)
		result_itoa = ft_uppercase(result_itoa);
	char_count = ft_putstr_fd(result_itoa, 1);
	free(result_itoa);
	return (char_count);
}

char	*ptr_itoa(uintptr_t n, char *base)
{
	char	*itoa;
	int		placed;
	int		i;

	placed = 0;
	itoa = malloc(sizeof(char) * 17);
	i = 0;
	while (i < 17)
		*(itoa + (i++)) = '\0';
	while (n >= 16 && placed < 16)
	{
		*(itoa + placed) = *(base + (n % 16));
		placed++;
		n /= 16;
	}
	*(itoa + placed) = *(base + n);
	return (strcpy_reversed(itoa, placed));
}

char	*strcpy_reversed(char *s, int placed)
{
	int		i;
	char	*final;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s);
	final = malloc(sizeof(char) * (s_len + 1));
	*(final + s_len) = '\0';
	while (i <= placed)
	{
		*(final + placed - i) = *(s + i);
		i++;
	}
	free(s);
	return (final);
}

int	print_pointer(unsigned long ptr)
{
	int		char_count;
	char	*itoa;
	int		itoa_len;

	itoa = ptr_itoa((uintptr_t) ptr, BASE_16);
	char_count = ft_putstr_fd("0x", 1);
	itoa_len = ft_strlen(itoa);
	if (itoa_len >= 17)
		itoa_len = 16;
	char_count += write(1, itoa, itoa_len);
	free(itoa);
	return (char_count);
}
