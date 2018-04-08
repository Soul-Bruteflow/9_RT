/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:26:07 by vholovin          #+#    #+#             */
/*   Updated: 2018/04/03 15:26:08 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

/*
** Transform struct definition.
*/
typedef struct	s_transform
{
	t_vec3		translation;
	t_quat		rotation;
	t_quat		rotx;
	t_quat		roty;
	t_vec2		angle;

}				t_transform;

t_transform		init_transform(void);
t_mat4			get_model(t_transform *t);

#endif
