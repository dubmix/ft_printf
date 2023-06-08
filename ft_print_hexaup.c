/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexaup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:45:55 by pdelanno          #+#    #+#             */
/*   Updated: 2023/03/21 13:35:16 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexaup(t_print *tab)
{
	unsigned int	nb;
	char			*base;
	char			tmp[16];
	int				i;

	nb = va_arg(tab->args, unsigned int);
	base = "0123456789ABCDEF";
	i = sub_hexa(tab, base, tmp, nb);
	if (tab->hashtag)
		tab->wdt -= 2;
	if (tab->wdt && !tab->dash)
		ft_right_align(tab, ft_strlen(tab, tmp));
	if (tab->hashtag)
		tab->totlen += write(1, "0X", 2);
	if (tab->prc)
		ft_precision(tab, ft_strlen(tab, tmp));
	while (--i >= 0)
		tab->totlen += write(1, &tmp[i], 1);
	if (tab->wdt && tab->dash)
		ft_left_align(tab, ft_strlen(tab, tmp));
}
