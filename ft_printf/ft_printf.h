/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:41:14 by ljahn             #+#    #+#             */
/*   Updated: 2022/05/09 12:10:06 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *base, ...);
int		ft_printchar(va_list arg);
int		ft_printstr(char *s);
int		ft_printptr(void *ptr);
int		ft_printnumb(int x);
int		ft_printunumb(unsigned int x);
int		ft_printhex(unsigned long x, int uppercase);

#endif