/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:10:26 by dangonza          #+#    #+#             */
/*   Updated: 2022/02/02 13:34:00 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"

// ft_printf.c
int		ft_printf(const char *str, ...);
int		print_special(va_list vlist, const char *str, int *last_printed);

// ft_itoa.c
char	*ft_itoa(long long int n, char *base, int base_len);

// util_functions.c
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
char	*ft_uppercase(char *s);

// print_specials.c
int		print_base10(long int num);
int		print_hex_ptr(uintptr_t n, char *base);
int		print_base16(long int num, int is_uppercase);
int		print_pointer(unsigned long ptr);
char	*ptr_itoa(uintptr_t n, char *base);
char	*strcpy_reversed(char *s, int placed);

#endif
