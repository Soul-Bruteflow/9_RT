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

int			get_plane(t_rt *r, int i, cJSON *pt)
{
	cJSON	*temp;
	int		n;

	temp = cJSON_GetObjectItem(pt, "plane");
	if (!(parse_plane(r, i, temp)))
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

int			get_plane_limit(t_rt *r, int i, cJSON *pt)
{
	cJSON	*temp;
	int		n;

	temp = cJSON_GetObjectItem(pt, "plane_limit");
	if (!(parse_plane_limit(r, i, temp)))
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

int			get_sphere(t_rt *r, int i, cJSON *pt)
{
	cJSON	*temp;
	int		n;

	temp = cJSON_GetObjectItem(pt, "sphere");
	if (!(parse_sphere(r, i, temp)))
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
