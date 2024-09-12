/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:30:18 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/12 19:35:07 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_digit_sign(char **str, int i)
{
	int	j;

	j = 0;
	if (ft_issign(str[i][j]))
		j++;
	while (str[i][j])
	{
		if (!ft_isdigit(str[i][j]))
			return (0);
		j++;
	}
	return (1);
}
