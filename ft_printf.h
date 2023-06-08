/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:28:04 by pdelanno          #+#    #+#             */
/*   Updated: 2023/03/21 15:18:03 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		lenwdt;
	int		prc;
	int		zero;
	int		neg;
	int		zeroflag;
	int		dash;
	int		sp;
	int		pos;
	int		hashtag;
	int		totlen;
}		t_print;

int		ft_eval_format(t_print *tab, char const *format, int i);
int		sub_eval(t_print *tab, char const *format, int i);
int		sub_prc(t_print *tab, char const *format, int i);
void	print_format(t_print *tab, char const *format, int i);
void	ft_print_char(t_print *tab);
void	ft_print_str(t_print *tab);
void	sub_str(t_print *tab, int prc, char *str);
void	ft_print_int(t_print *tab);
int		sub_int(t_print *tab, int nb, int tmp_nb);
void	ft_print_unsignedint(t_print *tab);
void	sub_unsignedint(t_print *tab, unsigned int nb);
void	ft_print_hexalo(t_print *tab);
int		sub_hexa(t_print *tab, char *base, char *tmp, unsigned int nb);
void	ft_print_hexaup(t_print *tab);
void	ft_print_address(t_print *tab);
int		sub_address(t_print *tab, unsigned long nb);
int		ft_strlen(t_print *tab, char *str);
void	ft_right_align(t_print *tab, int nb);
void	sub_rightalign(t_print *tab);
void	ft_left_align(t_print *tab, int nb);
void	ft_precision(t_print *tab, int nb);
int		ft_printf(const char *format, ...);

#endif
