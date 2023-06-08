/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:11:19 by pdelanno          #+#    #+#             */
/*   Updated: 2023/03/20 16:29:08 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(t_print *tab, char *str)
{
	int	i;
	int	nb;
	int	prc;

	i = 0;
	nb = 1;
	prc = tab->prc;
	if (prc > 0)
	{
		while (str[i] && prc > 0)
		{
			i++;
			prc--;
		}
	}
	else
	{
		while (str[i])
			i++;
	}
	while (i-- != 1)
		nb = nb * 10;
	return (nb);
}

void	ft_right_align(t_print *tab, int nb)
{
	if (tab->prc >= tab->wdt)
		return ;
	if (nb < 0)
	{
		nb = -nb;
		tab->lenwdt += 1;
		tab->neg = 1;
	}	
	while (nb > 9)
	{
		nb = nb / 10;
		tab->lenwdt += 1;
	}
	sub_rightalign(tab);
}

void	sub_rightalign(t_print *tab)
{
	if (tab->prc)
	{
		while (tab->wdt - tab->prc - tab->neg)
		{
			tab->totlen += write(1, " ", 1);
			tab->wdt -= 1;
		}
	}
	else
	{
		if (tab->pos || tab->sp)
			tab->wdt -= 1;
		while (tab->wdt - tab->lenwdt)
		{
			tab->totlen += write(1, " ", 1);
			tab->wdt -= 1;
		}
	}
}

void	ft_left_align(t_print *tab, int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		tab->lenwdt += 1;
		tab->neg = 1;
	}	
	while (nb > 9)
	{
		nb = nb / 10;
		tab->lenwdt += 1;
	}
	while (tab->wdt - tab->lenwdt)
	{
		tab->totlen += write(1, " ", 1);
		tab->wdt -= 1;
	}
}

void	ft_precision(t_print *tab, int nb)
{
	if (tab->zeroflag)
		tab->prc = tab->wdt;
	if (nb < 0)
	{
		nb = -nb;
		tab->zero += 1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		tab->zero += 1;
	}
	while (tab->prc - tab->zero - tab->zeroflag)
	{
		tab->totlen += write(1, "0", 1);
		tab->prc -= 1;
	}
}
