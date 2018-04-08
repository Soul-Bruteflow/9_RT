/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_radians.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:08:24 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:08:26 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	ft_to_radians(float degrees)
{
	return ((float)(degrees * M_PI / 180));
}

float	ft_to_degree(float radians)
{
	return ((float)(radians * 180 / M_PI));
}
