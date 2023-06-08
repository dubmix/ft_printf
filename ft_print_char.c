/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:02 by pdelanno          #+#    #+#             */
/*   Updated: 2023/03/21 09:51:20 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->wdt && !tab->dash)
		ft_right_align(tab, 0);
	tab->totlen += write(1, &c, 1);
	if (tab->wdt && tab->dash)
		ft_left_align(tab, 0);
}
