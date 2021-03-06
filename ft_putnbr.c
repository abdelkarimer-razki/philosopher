/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:56:27 by aer-razk          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:30 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_putnbr_fd(int n)
{
	long int	k;

	k = n;
	if (k < 0)
	{
		write(1, "-", 1);
		k = -k;
	}
	if (k >= 0)
	{
		if (k < 10)
			write (1, &"0123456789"[k], 1);
		else
		{
			ft_putnbr_fd(k / 10);
			write(1, &"0123456789"[k % 10], 1);
		}
	}
}
