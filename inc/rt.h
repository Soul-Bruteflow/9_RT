/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:59:54 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/04/03 17:00:18 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RT_H
# define _RT_H

/*
** I Order
*/
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include "math/math.h"
# include "math/vectors.h"
# include "math/quaternions.h"
# include "math/matrices.h"
# include "math/polinoms.h"

/*
** II Order
*/
# include "utility/bool.h"
# include "utility/defines.h"
# include "utility/errors.h"
# include "utility/utility.h"

/*
** III Order
*/
# include "rt/transform.h"
# include "rt/raytrace.h"
# include "rt/objects.h"
# include "rt/camera.h"
# include "rt/textures.h"

/*
** IV Order
*/
# include "controls/controls.h"

/*
** Phtreads
*/
# include <pthread.h>

/*
** Parser cJSON
*/
# include "cJSON.h"

# include "libft.h"

/*
** Basic SDL2 variables
** key_state - current key code
*/
typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	const Uint8		*key_state;
	t_mouse			mouse;
}					t_sdl;

/*
** Window draw
** screen - texture on which drawing is happening
** draw_buf - content of draw buffer is updated on to the texture
** each redraw call.
** pitch - the length of a row of pixels in bytes
** offset - draw location in draw buffer
*/
typedef struct		s_win
{
	SDL_Texture		*screen;
	Uint8			*draw_buf;
	int				pitch;
	size_t			offset;
	Uint16			width;
	Uint16			height;
	char			*title;
}					t_win;
/*
** Scene
*/
typedef struct		s_scene
{
	t_obj3d			**objects;
	t_material		**materials;
	t_light			**lights;
	t_ray			ray;
	t_cam			cam;
	int				objs_n;
	int				mats_n;
	int				lits_n;
	int				aa;
	int				max_level_reflection;
	int				max_level_transparent;
	t_bool			status_texture;
	t_bool			status_shadow;
	t_bool			status_glossy;
	int				status_color;
}					t_scene;
/*
** Support struct for calculation
*/
typedef struct		s_calc
{
	t_rgbap			color;
	t_rgbap			sum_color;
	t_rgba			pixel_color;
	int				cur_obj;
	t_vec3			intersect_normal;
	t_vec3			old_start;
	t_vec3			new_start;
	t_material		cur_mat;
	int				material_n;
	float			cur_power_ray;
	int				level_reflection;
	int				level_transparent;
	t_rgbap			shadow;
	t_rgbap			light;
	int				i;
	int				n;
	t_bool			last_status_refract;
}					t_calc;
/*
** Parser struct
*/
typedef	struct		s_pars
{
	int				fd;
	int				n;
	char			**av;
	char			*line;
}					t_pars;

typedef struct		s_time
{
	uint32_t		oldtime;
	uint32_t		curtime;
	double			ftime;
	char			fps[4];
	int				fps_counter;
	float			fps_rate;
	float			delta_time;
}					t_time;
/*
** Main struct.
** av - ./RTv1 arguments
*/
typedef struct		s_rt
{
	char			**av;
	t_sdl			*sdl;
	t_win			*win;
	t_scene			*scene;
	t_calc			*calc;
	t_pars			*pars;
	t_time			delta;
	SDL_Texture		*img;
	SDL_Rect		texr;
	int				w;
	int				h;
	TTF_Font		*font;
	SDL_Color		fcolor;
	SDL_Texture		*tex_message;
	SDL_Rect		message_rect;
	int				t_w;
	int				t_h;
	t_bool			togle_info;
	t_bool			on;
	t_bool			show;
}					t_rt;

typedef struct		s_rt_pth
{
	t_rt			*rt;
	int				i;
}					t_rt_pth;
/*
** Parser cJSON
*/
t_bool				parse_int_number_json_vers(int *n, int min, int max);
t_bool				parse_number_json_vers(float *n, int min, int max);
t_bool				parse_vector_json_vers(t_vec3 *v, int min, int max);
t_bool				parse_float_number_json_vers(float *n,
						float min, float max);
t_bool				parse_color_json_vers(t_rgbap *c, float min, float max);
t_bool				parse_vector_float_json_vers(t_vec3 *v,
						float min, float max);
char				*get_json_string(char *mapname);
t_vec3				obj_rotation(t_vec3 vec, t_vec3 pos, t_vec3 rot);
/*
** Parser
*/
t_bool				parser_core(t_rt *r);
t_bool				parse_scene(t_rt *r);
t_bool				parse_render(t_rt *r);
t_bool				parse_camera(t_rt *r);
t_bool				parse_lights(t_rt *r);
/*
** Parser materials
*/
t_bool				parse_materials(t_rt *r);
t_bool				parse_mats_scale_array_1(t_rt *r, cJSON *elem, int i);
t_bool				parse_mats_offset(t_rt *r);
t_bool				parse_mats_texture_1(t_rt *r, cJSON *pt, int i);
t_bool				parse_mats_offset_single(t_rt *r, cJSON *temp, int i);
t_bool				parse_mats_offset_array(t_rt *r, cJSON *temp, int i);
t_bool				parse_mats_transparent_1(t_rt *r, cJSON *pt, int i);
t_bool				parse_mats_color(t_rt *r);
t_bool				parse_mats_color_1(t_rt *r, cJSON *temp, int i);
t_bool				parse_mats_refraction(t_rt *r);
t_bool				parse_mats_transparent(t_rt *r);
t_bool				parse_mats_reflection(t_rt *r);
t_bool				parse_mats_texture(t_rt *r);
/*
** Parser object
*/
t_bool				parse_objects(t_rt *r);
int					get_torus(t_rt *r, int i, cJSON *pt);
int					get_paraboloid(t_rt *r, int i, cJSON *pt);
int					get_ellipsoid(t_rt *r, int i, cJSON *pt);
int					get_cone(t_rt *r, int i, cJSON *pt);
int					get_cylinder(t_rt *r, int i, cJSON *pt);
int					get_sphere(t_rt *r, int i, cJSON *pt);
int					get_plane_limit(t_rt *r, int i, cJSON *pt);
int					get_plane(t_rt *r, int i, cJSON *pt);
/*
** Parser plane
*/
t_bool				parse_plane(t_rt *rt, int i, cJSON *temp);
t_bool				parse_plane_validation_array_pos(cJSON *elem, char *str);
t_vec3				parse_plane_single_rot(cJSON *temp);
t_bool				parse_plane_validation_material(cJSON *temp);
t_bool				parse_plane_fin_valid(t_rt *rt, t_vec3 pos, t_vec3 rot,
						float mat);
t_bool				parse_plane_single(t_rt *rt, int i, cJSON *temp);
t_bool				parse_plane_validation_single(cJSON *temp, char *str);
t_vec3				parse_plane_single_pos(cJSON *temp);
void				alloc_new_plane(t_rt *rt, int i);
/*
** Parser plane_limit
*/
t_bool				parse_plane_limit(t_rt *rt, int i, cJSON *temp);
t_bool				parse_plane_l_validation_single(cJSON *temp, char *str);
t_bool				parse_plane_validation_value(cJSON *temp, char *str);
t_vec3				parse_plane_l_single_pos(cJSON *temp);
t_vec3				parse_plane_l_single_rot(cJSON *temp);
t_bool				parse_plane_l_fin_valid(t_vec3 pos, t_vec3 rot,
						float h, float w);
void				alloc_new_plane_limit(t_rt *rt, int i);
/*
** Parser sphere
*/
t_bool				parse_sphere(t_rt *rt, int i, cJSON *temp);
t_bool				parse_sphere_validation_single(cJSON *temp, char *str);
t_vec3				parse_sphere_single_pos(cJSON *temp);
t_bool				parse_sphere_validation_value(cJSON *temp, char *str);
void				alloc_new_sphere(t_rt *rt, int i);
/*
** Parser cylinder
*/
t_bool				parse_cylinder(t_rt *rt, int i, cJSON *temp);
t_bool				parse_cyl_valid_all(cJSON *temp);
t_vec3				parse_cyl_single_pos(cJSON *temp);
t_vec3				parse_cyl_single_rot(cJSON *temp);
t_bool				parse_cyl_validation_value(cJSON *temp, char *str);
t_bool				parse_cyl_validation_single(cJSON *temp, char *str);
void				alloc_new_cylinder(t_rt *rt, int i);
/*
** Parser cone
*/
t_bool				parse_cone(t_rt *rt, int i, cJSON *temp);
t_bool				parse_cone_valid_all(cJSON *temp);
t_vec3				parse_cone_single_pos(cJSON *temp);
t_vec3				parse_cone_single_rot(cJSON *temp);
t_bool				parse_cone_validation_value(cJSON *temp, char *str);
void				alloc_new_cone(t_rt *rt, int i);
/*
** Parser ellipsoid
*/
t_bool				parse_ellipsoid(t_rt *rt, int i, cJSON *temp);
t_bool				parse_ellip_valid_all(cJSON *temp);
t_bool				parse_ellip_fin_valid(t_vec3 pos, t_vec3 rot, float k,
						float rad);
t_vec3				parse_ellip_single_pos(cJSON *temp);
t_vec3				parse_ellip_single_rot(cJSON *temp);
void				alloc_new_ellipsoid(t_rt *rt, int i);
/*
** Parser paraboloid
*/
t_bool				parse_paraboloid(t_rt *rt, int i, cJSON *temp);
t_bool				parse_parab_valid_all(cJSON *temp);
t_bool				parse_parab_fin_valid(t_vec3 pos, t_vec3 rot, float a);
t_vec3				parse_parab_single_pos(cJSON *temp);
t_vec3				parse_parab_single_rot(cJSON *temp);
void				alloc_new_paraboloid(t_rt *rt, int i);
/*
** Parser disc
*/
t_bool				parse_disc(t_rt *rt, int i, cJSON *temp);
t_bool				parse_disc_valid_all(cJSON *temp);
t_vec3				parse_disc_single_pos(cJSON *temp);
t_vec3				parse_disc_single_rot(cJSON *temp);
void				alloc_new_disc(t_rt *rt, int i);
/*
** Parser torus
*/
t_bool				parse_torus(t_rt *rt, int i, cJSON *temp);
t_bool				parse_torus_valid_all(cJSON *temp);
t_vec3				parse_torus_single_pos(cJSON *temp);
t_vec3				parse_torus_single_rot(cJSON *temp);
void				alloc_new_torus(t_rt *rt, int i);
/*
** Parser triangle
*/
t_bool				parse_triangle(t_rt *rt, int i, cJSON *temp);
t_bool				parse_triangle_valid_all(cJSON *temp);
t_vec3				parse_triangle_single_a(cJSON *temp);
t_vec3				parse_triangle_single_b(cJSON *temp);
t_vec3				parse_triangle_single_c(cJSON *temp);
t_bool				parse_validation_single_dot(cJSON *temp2, char *str);
t_bool				parse_triangle_valid_value(cJSON *temp, char *str);
void				alloc_new_triangle(t_rt *rt, int i);
/*
** Parser Lights
*/
t_bool				parse_lights_color(t_rt *r);
t_bool				parse_lights_color_array(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_color_single(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_color_detail(t_rt *r, cJSON *temp2, int i,
						char *color);
t_bool				parse_lights_power(t_rt *r);
t_bool				parse_lights_power_array(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_power_single(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_len(t_rt *r);
t_bool				parse_lights_len_array(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_len_single(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_angle(t_rt *r);
t_bool				parse_lights_angle_array(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_angle_single(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_direction(t_rt *r);
t_bool				parse_lights_direction_array(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_direction_single(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_direction_single_dot(t_rt *r, cJSON *temp2,
						int i, char *dot);
t_bool				parse_lights_position(t_rt *r);
t_bool				parse_lights_pos_array(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_pos_single(t_rt *r, cJSON *temp, int i);
t_bool				parse_lights_pos_single_dot(t_rt *r, cJSON *temp2, int i,
						char *dot);
t_bool				parse_lights_type(t_rt *r);
t_bool				read_lights_type_single(t_rt *r, cJSON *temp, int i);
t_bool				read_lights_type_array(t_rt *r, cJSON *temp, int i);
/*
** Parser Render
*/
t_bool				parse_render_info_aa(t_rt *r, cJSON *temp);
t_bool				parse_render_info_typecol(t_rt *r, cJSON *temp);
t_bool				parse_render_info_lvl_refl(t_rt *r, cJSON *temp);
t_bool				parse_render_info_lvl_refr(t_rt *r, cJSON *temp);
t_bool				parse_render_info_texture(t_rt *r, cJSON *temp);
t_bool				parse_render_info_shadow(t_rt *r, cJSON *temp);
t_bool				parse_render_info_glossy(t_rt *r, cJSON *temp);
/*
** other
*/
void				open_file(t_rt *r);
void				close_file(t_rt *r);
void				gnl_error(t_rt *r, int i);
float				ft_atof(const char *s);
t_bool				get_str(t_rt *r);
t_bool				parse_vector(t_rt *r, t_vec3 *v, int min, int max);
t_bool				parse_vector_float(t_rt *r, t_vec3 *v, float min,
						float max);
t_bool				parse_number(t_rt *r, float *n, int min, int max);
t_bool				parse_color(t_rt *r, t_rgbap *c, float min, float max);
t_bool				parse_float_number(t_rt *r, float *n, float min, float max);
t_bool				check_line(t_rt *r, const char *s);
t_bool				valid_texture(t_rt *r, t_texture *t, int min, int max);
t_bool				valid_material(t_rt *r, float material, int min, int max);
/*
** RT
*/
t_rt				*rt_init(char **av);
void				rt_render(t_rt *r);
void				rt_loop(t_rt *r);
void				ft_noise(t_rt *r);
void				rt_quit(t_rt *r);
/*
** Raycast
*/
t_bool				object_intersect(t_rt *rt);
void				normal_of_intersect(t_rt *rt, t_vec3 *n);
void				pthreads(t_rt *rt);
void				*raytrace(void *arg);
void				calculate_ray(t_rt *rt);
void				calculate_ambient_light(t_rt *rt);
void				calculate_light(t_rt *rt);
void				calculate_illumination(t_rt *rt, t_light cur_light,
						t_vec3 v_dist, float dist);
void				calculate_shadow(t_rt *rt, t_light cur_light, t_vec3 v_dist,
						float dist);
void				shadow(t_rt *rt_last, t_rt *rt_cur, t_light cur_light,
						t_obj3d **objs);
void				calculate_reflect_refract(t_rt *rt);
void				calculate_reflection(t_rt *rt, t_rgbap *c_refl);
void				calculate_refraction(t_rt *rt, t_rgbap *c_refr);
void				calculate_frenel(t_rt *rt_last, t_rt *rt_cur, float *kr);
void				color_filters(t_rgbap *color, int status_color);

t_rt				*ft_copy(t_rt *rt_orig);
void				ft_free(t_rt *rt_free);
/*
** Scene
*/
void				init_camera(t_rt *r);
void				new_scene(t_rt *r, int n_of_lights, int n_of_mats,
						int n_of_objs);
void				create_sceen_one(t_scene *scene);
t_bool				create_scene(t_rt *r);
t_obj3d				*new_object(t_obj_type object_type);
/*
** General controls
*/
void				init_controls(t_rt *r);
/*
** Keyboard
*/
void				keyboard_core(t_rt *r);
void				camera_movement(t_rt *r);
void				camera_rotation(t_rt *r);
void				camera_vertical_rotation(t_rt *r);
void				camera_horizontal_rotation(t_rt *r);
void				camera_freelook(t_rt *r);
void				camera_vertical_freelook(t_rt *r);
void				camera_horizontal_freelook(t_rt *r);
void				render_flags(t_rt *rt);
void				print_screen(t_rt *r);
void				info_togle(t_rt *r);
/*
** Mouse
*/
void				mouse_core(t_rt *r);
/*
** Window
*/
void				create_window(t_rt *r, Uint16 wdth, Uint16 hght,
						const char *title);
void				clear_window(t_rt *r);
void				render_present(t_rt *r);
void				ft_draw_pixel(Uint16 x, Uint16 y, t_rgba *color,
						Uint8 *draw_buffer);
void				rerender(t_rt *r);
/*
** Texture
*/
void				calculate_texture(t_rt *rt);
void				cylinder_mapping(t_rt *rt, int *x, int *y);
void				planar_mapping(t_rt *rt, int *x, int *y);
void				sphere_mapping(t_rt *rt, int *x, int *y);
/*
** GUI
*/
void				init_gui(t_rt *r);
void				refresh_gui(t_rt *r);

#endif
