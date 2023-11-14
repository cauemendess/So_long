/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:57:00 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/14 12:00:47 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long int nb, char *base)
{
	int	base_len;
	int	len;

	len = 0;
	base_len = ft_strlen_printf(base);
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= base_len)
		len += ft_putnbr_base(nb / base_len, base);
	len += ft_putchar(base[nb % base_len]);
	return (len);
}
