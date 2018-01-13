/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:12:38 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		set_vector3(float x, float y, float z)
{
	t_vec3 tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

t_vec2		set_vector2(float x, float y)
{
	t_vec2 tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp);
}
