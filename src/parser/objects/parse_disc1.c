/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:04:31 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/04/02 14:13:11 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool		parse_disc_validation_single_dot(cJSON *temp2, char *str)
{
	cJSON *temp3;

	temp3 = cJSON_GetObjectItem(temp2, str);
	if (!temp3)
		return (false);
	if (temp3->type != cJSON_Number)
		return (false);
	return (true);
}

t_bool		parse_disc_validation_single(cJSON *temp, char *str)
{
	cJSON *temp2;

	temp2 = cJSON_GetObjectItem(temp, str);
	if (!temp2)
		return (false);
	if (temp2->type == cJSON_Object)
	{
		if (!(parse_disc_validation_single_dot(temp2, "x")))
			return (false);
		if (!(parse_disc_validation_single_dot(temp2, "y")))
			return (false);
		if (!(parse_disc_validation_single_dot(temp2, "z")))
			return (false);
	}
	else
		return (false);
	return (true);
}

t_bool		parse_disc_validation_value(cJSON *temp, char *str)
{
	cJSON *temp2;

	temp2 = cJSON_GetObjectItem(temp, str);
	if (!temp2)
		return (false);
	if (temp2->type != cJSON_Number)
		return (false);
	return (true);
}

t_bool		parse_disc_valid_all(cJSON *temp)
{
	if (!(parse_disc_validation_single(temp, "position")))
		return (false);
	if (!(parse_disc_validation_single(temp, "rotate")))
		return (false);
	if (!(parse_disc_validation_value(temp, "large_radius")))
		return (false);
	if (!(parse_disc_validation_value(temp, "small_radius")))
		return (false);
	if (!(parse_disc_validation_value(temp, "material")))
		return (false);
	return (true);
}
