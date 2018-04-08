/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:40:07 by vholovin          #+#    #+#             */
/*   Updated: 2018/04/03 17:12:09 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef enum	e_obj_type
{
	sphere,
	plane,
	plane_limit,
	cylinder,
	cone,
	ellipsoid,
	paraboloid,
	torus,
	triangle,
	disc
}				t_obj_type;

typedef struct	s_shpere
{
	float		radius;
}				t_sphere;

typedef struct	s_plane
{
	t_vec3		bla;
}				t_plane;

typedef struct	s_plane_limit
{
	t_vec3		d1;
	t_vec3		d2;
	t_vec3		d3;
	t_vec3		d4;

}				t_plane_limit;

typedef struct	s_cylinder
{
	float		radius;
}				t_cylinder;

typedef struct	s_cone
{
	float		angle;
}				t_cone;

typedef struct	s_ellipsoid
{
	float		k;
	float		rad;
}				t_ellipsoid;

typedef struct	s_torus
{
	float		r1;
	float		r;
}				t_torus;

typedef struct	s_paraboloid
{
	float		a;
}				t_paraboloid;

typedef struct	s_triangle
{
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;
}				t_triangle;

typedef struct	s_disc
{
	float		r1;
	float		r;
}				t_disc;
/*
** Object
*/
typedef struct	s_obj3d
{
	void		*type;
	t_obj_type	obj_type;
	t_vec3		pos;
	t_vec3		rot;
	Uint16		material;
	void		(*normal)(t_ray *, struct s_obj3d *, struct s_vec3 *);
	t_bool		(*intersect)(t_ray *, struct s_obj3d *, float *);
}				t_obj3d;
/*
** General
*/
void			set_object_position(t_obj3d *obj, t_vec3 new_position);
void			set_object_rotation(t_obj3d *obj, t_vec3 new_rotation);
void			set_object_material(t_obj3d *obj, Uint16 new_material);
/*
** Plane
*/
t_plane			*new_plane();
void			set_plane(t_obj3d *obj, t_vec3 pos, t_vec3 rot, Uint16 mat);
void			normal_plane(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_plane(t_ray *r, t_obj3d *object, float *d);
/*
** Plane_limit
*/
t_plane_limit	*new_plane_limit();
void			set_plane_limit(t_obj3d *obj, t_vec3 *pr, float *hw,
					Uint16 mat);
void			normal_plane_limit(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_plane_limit(t_ray *r, t_obj3d *object, float *d);
/*
** Sphere
*/
t_sphere		*new_sphere();
void			set_sphere(t_obj3d *obj, t_vec3 pos, float rad, Uint16 mat);
void			normal_sphere(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_sphere(t_ray *r, t_obj3d *obj, float *d);
/*
** Cylinder
*/
t_cylinder		*new_cylinder();
void			set_cylinder(t_obj3d *obj, t_vec3 *pr, float rad, Uint16 mat);
void			normal_cylinder(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_cylinder(t_ray *r, t_obj3d *obj, float *d);
/*
** Cone
*/
t_cone			*new_cone();
void			set_cone(t_obj3d *obj, t_vec3 *pr, float angle, Uint16 mat);
void			normal_cone(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_cone(t_ray *r, t_obj3d *obj, float *d);
/*
** Ellipsoid
*/
t_ellipsoid		*new_ellipsoid();
void			set_ellipsoid(t_obj3d *obj, t_vec3 *pr, float *krm, Uint16 mat);
void			normal_ellipsoid(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_ellipsoid(t_ray *r, t_obj3d *obj, float *d);
/*
** Paraboloid
*/
t_paraboloid	*new_paraboloid();
void			set_paraboloid(t_obj3d *obj, t_vec3 *pr, float a, Uint16 mat);
void			normal_paraboloid(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_paraboloid(t_ray *r, t_obj3d *obj, float *d);
/*
** Torus
*/
t_torus			*new_torus();
void			set_torus(t_obj3d *obj, t_vec3 *pr, float *lrsrm, Uint16 mat);
void			normal_torus(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_torus(t_ray *r, t_obj3d *object, float *d);
/*
** disc
*/
t_disc			*new_disc();
void			set_disc(t_obj3d *obj, t_vec3 *pr, float *r1rm, Uint16 mat);
void			normal_disc(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_disc(t_ray *r, t_obj3d *object, float *d);
/*
** triangle
*/
t_triangle		*new_triangle();
void			set_triangle(t_obj3d *obj, t_vec3 *abc, Uint16 mat);
void			normal_triangle(t_ray *r, t_obj3d *obj, t_vec3 *n);
t_bool			intersect_triangle(t_ray *r, t_obj3d *object, float *d);

#endif
