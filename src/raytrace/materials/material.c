/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:29:25 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material	*new_material(void)
{
	t_material *new_material;

	new_material = malloc(sizeof(*(new_material)));
	if (new_material == NULL)
		rtv_error(malloc_error);
	return (new_material);
}

void		set_material(t_material *material, t_rgbap diffuse, float reflect)
{
	material->diffuse.red = diffuse.red;
	material->diffuse.green = diffuse.green;
	material->diffuse.blue = diffuse.blue;
	material->diffuse.alpha = diffuse.alpha;
	material->reflection = reflect;
}
