/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:04:37 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 16:05:40 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _OBJECTS_H
# define _OBJECTS_H

typedef enum	e_obj_type
{
	sphere,
	plane,
	cylinder,
	cone
}				t_obj_type;

/*
** SPHERE primitive definition
*/
typedef struct	s_shpere
{
	float		radius;
}				t_sphere;

/*
** PLANE primitive definition
*/
typedef struct	s_plane
{
	t_vec3d		normal;
	t_vec3d		point;
}				t_plane;

/*
** CYLINDER primitive definition
*/
typedef struct	s_cylinder
{
	t_vec3d		a;
	t_vec3d		b;
	float		radius;
}				t_cylinder;

/*
** CONE primitive definition
** param[0] - radius;
** param[1] - height;
*/
typedef struct	s_cone
{
	float		angle;
	t_vec3d		axis;
}				t_cone;

/*
** Object
*/
typedef struct	s_obj3d
{
	void		*type;
	t_obj_type	obj_type;
	t_bool		hit;
	t_vec3d		pos;
	Uint16		material;
	t_bool		(*intersect)(t_ray *, struct s_obj3d *, float *);
}				t_obj3d;

/*
** General
*/
void			set_object_position(t_obj3d *obj, t_vec3d new_position);
void			set_object_material(t_obj3d *obj, Uint16 new_material);
/*
** Plane
*/
t_plane			*new_plane();
void			set_plane_normal(t_obj3d *obj, t_vec3d new_normal);
void			set_plane(t_obj3d *obj, t_vec3d new_normal, t_vec3d point,
				Uint16 new_material);
t_bool			intersect_plane_ray(t_ray *r, t_obj3d *object, float *t);
/*
** Sphere
*/
t_sphere		*new_sphere();
void			set_sphere_radius(t_obj3d *obj, float new_radius);
void			set_sphere(t_obj3d *obj, t_vec3d pos, float rad, Uint16 mat);
t_bool			intersect_sphere_ray(t_ray *r, t_obj3d *object, float *t);
/*
** Cylinder
*/
t_cylinder		*new_cylinder();
void			set_cylinder_radius(t_obj3d *obj, float new_radius);
void			set_cylinder(t_obj3d *obj, t_vec3d *ab, float new_radius,
				Uint16 new_material);
t_bool			intersect_cylinder_ray(t_ray *r, t_obj3d *object, float *t);
/*
** Cone
*/
t_cone			*new_cone();
void			set_cone(t_obj3d *obj, t_vec3d *data, float angle,
				Uint16 new_material);
void			set_cone_axis(t_obj3d *obj, t_vec3d new_axis);
void			set_cone_angle(t_obj3d *obj, float new_angle);
t_bool			intersect_cone_ray(t_ray *r, t_obj3d *object, float *t);

#endif
