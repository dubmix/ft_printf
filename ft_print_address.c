/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:28:40 by pdelanno          #+#    #+#             */
/*   Updated: 2023/03/21 15:12:04 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_address(t_print *tab)
{
	unsigned long		nb;
	char				*base;
	char				tmp[16];
	int					i;

	nb = va_arg(tab->args, unsigned long);
	base = "0123456789abcdef";
	tmp[0] = '0';
	tmp[1] = 'x';
	i = 2;
	if (sub_address(tab, nb))
		return ;
	while (nb > 0)
	{
		tmp[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	if (tab->wdt && !tab->dash)
		ft_right_align(tab, ft_strlen(tab, tmp));
	tab->totlen += write (1, "0x", 2);
	while (--i >= 2)
		tab->totlen += write(1, &tmp[i], 1);
	if (tab->wdt && tab->dash)
		ft_left_align(tab, ft_strlen(tab, tmp));
}

int	sub_address(t_print *tab, unsigned long nb)
{	
	if (nb == 0)
	{
		tab->totlen += write(1, "(nil)", 5);
		return (1);
	}
	else
		return (0);
}
