/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2018/03/31 19:21:34 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			get_cylinder(t_rt *r, int i, cJSON *pt)
{
	cJSON	*temp;
	int		n;

	temp = cJSON_GetObjectItem(pt, "cylinder");
	if (!(parse_cylinder(r, i, temp)))
		return (-1);
	if (temp->type == cJSON_Object)
		i++;
	else if (temp->type == cJSON_Array)
	{
		n = cJSON_GetArraySize(temp);
		i += n;
	}
	return (i);
}

int			get_cone(t_rt *r, int i, cJSON *pt)
{
	cJSON	*temp;
	int		n;

	temp = cJSON_GetObjectItem(pt, "cone");
	if (!(parse_cone(r, i, temp)))
		return (-1);
	if (temp->type == cJSON_Object)
		i++;
	else if (temp->type == cJSON_Array)
	{
		n = cJSON_GetArraySize(temp);
		i += n;
	}
	return (i);
}

int			get_ellipsoid(t_rt *r, int i, cJSON *pt)
{
	cJSON	*temp;
	int		n;

	temp = cJSON_GetObjectItem(pt, "ellipsoid");
	if (!(parse_ellipsoid(r, i, temp)))
		return (-1);
	if (temp->type == cJSON_Object)
		i++;
	else if (temp->type == cJSON_Array)
	{
		n = cJSON_GetArraySize(temp);
		i += n;
	}
	return (i);
}

int			get_paraboloid(t_rt *r, int i, cJSON *pt)
{
	cJSON	*temp;
	int		n;

	temp = cJSON_GetObjectItem(pt, "paraboloid");
	if (!(parse_paraboloid(r, i, temp)))
		return (-1);
	if (temp->type == cJSON_Object)
		i++;
	else if (temp->type == cJSON_Array)
	{
		n = cJSON_GetArraySize(temp);
		i += n;
	}
	return (i);
}

int			get_torus(t_rt *r, int i, cJSON *pt)
{
	cJSON	*temp;
	int		n;

	temp = cJSON_GetObjectItem(pt, "torus");
	if (!(parse_torus(r, i, temp)))
		return (-1);
	if (temp->type == cJSON_Object)
		i++;
	else if (temp->type == cJSON_Array)
	{
		n = cJSON_GetArraySize(temp);
		i += n;
	}
	return (i);
}
