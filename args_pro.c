/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_pro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:56:20 by aer-razk          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:21 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isntdigit(char *arv)
{
	int	i;

	i = -1;
	while (arv[++i])
	{
		if ((arv[i] == '-' || arv[i] == '+') && (i == 0))
			i++;
		else if ((arv[i] == '-' || arv[i] == '+') && (i > 0))
			return (1);
		if (arv[i] > '9' || arv[i] < '0')
			return (1);
	}
	if (i == 0)
		return (1);
	return (-1);
}

int	args_protection(int arc, char **arv)
{
	int	i;

	i = 0;
	if (arc != 5 && arc != 6)
		return (1);
	while (arv[++i])
		if (ft_isntdigit(arv[i]) == 1 || ft_atoi(arv[i]) < 0)
			return (1);
	return (-1);
}
