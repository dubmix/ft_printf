/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:15:07 by pdelanno          #+#    #+#             */
/*   Updated: 2023/03/21 15:20:46 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format(t_print *tab, char const *format, int i)
{
	if (format[i] == 37)
	{
		tab->totlen += write(1, "%", 1);
		return (i);
	}
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'd'
		&& format[i] != 'i' && format[i] != 'u' && format[i] != 'x'
		&& format[i] != 'X' && format[i] != 'p')
	{
		i = sub_eval(tab, format, i);
		while (format[i] <= 57 && format[i] >= 48)
		{	
			tab->wdt = (tab->wdt * 10) + (format[i] - 48);
			i++;
		}
		i = sub_prc(tab, format, i);
	}
	print_format(tab, format, i);
	return (i);
}

int	sub_prc(t_print *tab, char const *format, int i)
{
	if (format[i] == '.')
	{
		i++;
		tab->zeroflag = 0;
		while (format[i] <= 57 && format[i] >= 48)
		{
			tab->prc = (tab->prc * 10) + (format[i] - 48);
			i++;
		}
	}
	return (i);
}

int	sub_eval(t_print *tab, char const *format, int i)
{
	if (format[i] == 48)
		tab->zeroflag = 1;
	if (format[i] == 45)
	{
		tab->dash = 1;
		tab->zeroflag = 0;
	}
	if (format[i] == 32)
		tab->sp = 1;
	if (format[i] == 43)
		tab->pos = 1;
	if (format[i] == 35)
		tab->hashtag = 1;
	i++;
	return (i);
}

void	print_format(t_print *tab, char const *format, int i)
{
	if (format[i] == 'c')
		ft_print_char(tab);
	if (format[i] == 's')
		ft_print_str(tab);
	if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(tab);
	if (format[i] == 'u')
		ft_print_unsignedint(tab);
	if (format[i] == 'x')
		ft_print_hexalo(tab);
	if (format[i] == 'X')
		ft_print_hexaup(tab);
	if (format[i] == 'p')
		ft_print_address(tab);
}
