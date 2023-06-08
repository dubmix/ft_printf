/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:45 by pdelanno          #+#    #+#             */
/*   Updated: 2023/03/21 15:01:32 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsignedint(t_print *tab)
{
	unsigned int	nb;
	char			tmp[16];
	int				i;
	unsigned int	temp;

	i = 0;
	nb = va_arg(tab->args, unsigned int);
	temp = nb;
	sub_unsignedint(tab, nb);
	while (nb > 0)
	{
		tmp[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	while (--i >= 0)
		tab->totlen += write(1, &tmp[i], 1);
	if (tab->wdt && tab->dash)
		ft_left_align(tab, temp);
}

void	sub_unsignedint(t_print *tab, unsigned int nb)
{
	if (tab->wdt && !tab->zeroflag && !tab->dash)
		ft_right_align(tab, nb);
	if (tab->sp)
		tab->totlen += write(1, " ", 1);
	if (tab->pos)
		tab->totlen += write(1, "+", 1);
	if (tab->prc || tab->zeroflag)
		ft_precision(tab, nb);
	if (nb == 0)
		tab->totlen += write(1, "0", 1);
}
