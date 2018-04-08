/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:06:47 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:06:49 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Hard clamp
*/

float	ft_clamp_f(float value, float lower, float upper)
{
	if (value > upper)
		value = upper;
	if (value < lower)
		value = lower;
	return (value);
}

/*
** Wrap around clamp
*/

float	ft_clamp_wf(float value, float lower, float upper)
{
	if (value > upper)
		value -= upper;
	if (value < lower)
		value += upper;
	return (value);
}
