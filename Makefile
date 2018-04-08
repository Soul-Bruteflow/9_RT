# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:24:38 by mvlad             #+#    #+#              #
#    Updated: 2017/10/18 17:03:12 by mvlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= RT

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

FRM_DIR	= ./frameworks/
SDL_INC	= $(FRM_DIR)SDL2.framework/Headers
SDL_TTF = $(FRM_DIR)SDL2_ttf.framework/Headers
SDL_IMG = $(FRM_DIR)SDL2_image.framework//Headers
SDL_MIX = $(FRM_DIR)SDL2_mixer.framework/Headers

LIB_DIR = ./libft/
LIB_INC = $(LIB_DIR)
LIB_LIB = $(LIB_DIR)libft.a

JSN_DIR = ./cJSON/
JSN_INC = $(JSN_DIR)
JSN_LIB = $(JSN_DIR)cJSON.a

OD :=	./obj \
		./obj/controls \
		./obj/controls/keyboard \
		./obj/controls/mouse \
		./obj/gui \
		./obj/parser \
		./obj/parser/objects \
		./obj/parser/scene \
		./obj/parser/scene/lights \
		./obj/parser/support \
		./obj/raytrace \
		./obj/raytrace/camera \
		./obj/raytrace/lights \
		./obj/raytrace/materials \
		./obj/raytrace/objects \
		./obj/raytrace/objects/cone \
		./obj/raytrace/objects/cylinder \
		./obj/raytrace/objects/disc \
		./obj/raytrace/objects/ellipsoid \
		./obj/raytrace/objects/paraboloid \
		./obj/raytrace/objects/plane \
		./obj/raytrace/objects/plane_limit \
		./obj/raytrace/objects/sphere \
		./obj/raytrace/objects/torus \
		./obj/raytrace/objects/triangle \
		./obj/raytrace/rays \
		./obj/raytrace/scene \
		./obj/raytrace/textures \
		./obj/transform \
		./obj/utility \
		./obj/utility/math \
		./obj/utility/math/matrices \
		./obj/utility/math/polinoms \
		./obj/utility/math/quaternions \
		./obj/utility/math/rotations \
		./obj/utility/math/vector \
		./obj/window

OBJ	=	controls/keyboard/camera_freelook.o \
		controls/keyboard/camera_movement.o \
		controls/keyboard/camera_rotation.o \
		controls/keyboard/gui_info.o \
		controls/keyboard/keyboard_core.o \
		controls/keyboard/print_screen.o \
		controls/keyboard/render_flags.o \
		controls/mouse/mouse_1.o \
		controls/mouse/mouse_2.o \
		controls/mouse/mouse_core.o \
		controls/controls.o \
		gui/init_gui.o \
		gui/refresh_gui.o \
		parser/objects/parse_cone.o \
		parser/objects/parse_cone1.o \
		parser/objects/parse_cone2.o \
		parser/objects/parse_cylinder.o \
		parser/objects/parse_cylinder1.o \
		parser/objects/parse_cylinder2.o \
		parser/objects/parse_disc.o \
		parser/objects/parse_disc1.o \
		parser/objects/parse_disc2.o \
		parser/objects/parse_ellipsoid.o \
		parser/objects/parse_ellipsoid1.o \
		parser/objects/parse_ellipsoid2.o \
		parser/objects/parse_materials0_0.o \
		parser/objects/parse_materials0_1.o \
		parser/objects/parse_materials1_0.o \
		parser/objects/parse_materials1_1.o \
		parser/objects/parse_materials2_0.o \
		parser/objects/parse_materials2_1.o \
		parser/objects/parse_materials3_0.o \
		parser/objects/parse_materials3_1.o \
		parser/objects/parse_objects.o \
		parser/objects/parse_objects1.o \
		parser/objects/parse_objects2.o \
		parser/objects/parse_paraboloid.o \
		parser/objects/parse_paraboloid1.o \
		parser/objects/parse_paraboloid2.o \
		parser/objects/parse_plane.o \
		parser/objects/parse_plane1.o \
		parser/objects/parse_plane2.o \
		parser/objects/parse_plane_limit.o \
		parser/objects/parse_plane_limit1.o \
		parser/objects/parse_plane_limit2.o \
		parser/objects/parse_sphere.o \
		parser/objects/parse_sphere1.o \
		parser/objects/parse_torus.o \
		parser/objects/parse_torus1.o \
		parser/objects/parse_torus2.o \
		parser/objects/parse_triangle.o \
		parser/objects/parse_triangle1.o \
		parser/objects/parse_triangle2.o \
		parser/scene/parse_camera.o \
		parser/scene/lights/parse_lights_core.o \
		parser/scene/lights/parse_lights_1.o \
		parser/scene/lights/parse_lights_2.o \
		parser/scene/lights/parse_lights_3.o \
		parser/scene/lights/parse_lights_4.o \
		parser/scene/lights/parse_lights_5.o \
		parser/scene/lights/parse_lights_6.o \
		parser/scene/lights/parse_lights_7.o \
		parser/scene/lights/parse_lights_8.o \
		parser/scene/lights/parse_lights_9.o \
		parser/scene/parse_render_0.o \
		parser/scene/parse_render_1.o \
		parser/scene/parse_scene.o \
		parser/support/parser_support_0.o \
		parser/support/parser_support_1.o \
		parser/support/parser_support_2.o \
		parser/support/parser_support_3.o \
		parser/parser_core.o \
		raytrace/camera/camera.o \
		raytrace/camera/camera_1.o \
		raytrace/lights/light.o \
		raytrace/materials/material.o \
		raytrace/objects/cone/cone_create.o \
		raytrace/objects/cone/cone_ray_intersect.o \
		raytrace/objects/cone/cone_ray_normal.o \
		raytrace/objects/cylinder/cylinder_create.o \
		raytrace/objects/cylinder/cylinder_ray_intersect.o \
		raytrace/objects/cylinder/cylinder_ray_normal.o \
		raytrace/objects/disc/disc_create.o \
		raytrace/objects/disc/disc_ray_intersect.o \
		raytrace/objects/disc/disc_ray_normal.o \
		raytrace/objects/ellipsoid/ellipsoid_create.o \
		raytrace/objects/ellipsoid/ellipsoid_ray_intersect.o \
		raytrace/objects/ellipsoid/ellipsoid_ray_normal.o \
		raytrace/objects/paraboloid/paraboloid_create.o \
		raytrace/objects/paraboloid/paraboloid_ray_intersect.o \
		raytrace/objects/paraboloid/paraboloid_ray_normal.o \
		raytrace/objects/plane/plane_create.o \
		raytrace/objects/plane/plane_ray_intersect.o \
		raytrace/objects/plane/plane_ray_normal.o \
		raytrace/objects/plane_limit/plane_limit_create.o \
		raytrace/objects/plane_limit/plane_limit_ray_intersect.o \
		raytrace/objects/plane_limit/plane_limit_ray_normal.o \
		raytrace/objects/sphere/sphere_create.o \
		raytrace/objects/sphere/sphere_ray_intersect.o \
		raytrace/objects/sphere/sphere_ray_normal.o \
		raytrace/objects/torus/torus_create.o \
		raytrace/objects/torus/torus_ray_intersect.o \
		raytrace/objects/torus/torus_ray_normal.o \
		raytrace/objects/triangle/triangle_create.o \
		raytrace/objects/triangle/triangle_ray_intersect.o \
		raytrace/objects/triangle/triangle_ray_normal.o \
		raytrace/objects/object.o \
		raytrace/rays/calculate_ambient_light.o \
		raytrace/rays/calculate_frenel.o \
		raytrace/rays/calculate_illumination.o \
		raytrace/rays/calculate_light.o \
		raytrace/rays/calculate_refl_refr.o \
		raytrace/rays/calculate_reflection.o \
		raytrace/rays/calculate_refraction.o \
		raytrace/rays/calculate_shadow_0.o \
		raytrace/rays/calculate_shadow_1.o \
		raytrace/rays/color_filters.o \
		raytrace/rays/intersect.o \
		raytrace/scene/scene_create.o \
		raytrace/textures/calculate_texture.o \
		raytrace/textures/cylinder_mapping.o \
		raytrace/textures/planar_mapping.o \
		raytrace/textures/sphere_mapping.o \
		raytrace/raytrace.o \
		raytrace/render.o \
		transform/transform.o \
		utility/math/matrices/inits_1.o \
		utility/math/matrices/inits_2.o \
		utility/math/matrices/inits_3.o \
		utility/math/matrices/mat_operations_1.o \
		utility/math/polinoms/polinom.o \
		utility/math/quaternions/quat_operations_1.o \
		utility/math/quaternions/quat_operations_2.o \
		utility/math/rotations/rotations.o \
		utility/math/vector/set_vector.o \
		utility/math/vector/vector_operations_1.o \
		utility/math/vector/vector_operations_2.o \
		utility/math/ft_to_radians.o \
		utility/ft_atof.o \
		utility/ft_draw_pixel.o \
		utility/ft_noise.o \
		utility/ft_set_color.o \
		utility/utility.o \
		window/create_window.o \
		window/update_window.o \
		errors.o \
		copy_free.o \
		main.o \
		pthreads.o \
		rt_init.o \
		rt_loop.o \
		rt_quit.o

LIB = $(LIB_LIB) $(JSN_LIB) 

HEADERS	= $(INC_DIR)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SDL		= -F $(FRM_DIR) -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer
INC_OPT = -I $(LIB_INC) -I $(JSN_INC) -I $(INC_DIR) -I $(SDL_INC) -I $(SDL_TTF) -I $(SDL_IMG) -I $(SDL_MIX)
OUT_OPT = -o
OBJ_OPT = $< -o $@
LIB_OPT	= -c
PTHREAD = -lpthread
OPTIMA	= -O3

RMF 	= rm -f
RMD		= rm -rf

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OD)
	$(CC) $(CFLAGS) $(LIB_OPT) $(OBJ_OPT) $(INC_OPT)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(JSN_DIR)
	@mkdir -p ~/Library
	@mkdir -p ~/Library/Frameworks

	@rm -rf ~/Library/Frameworks/SDL2.framework ~/Library/Frameworks/SDL2_image.framework ~/Library/Frameworks/SDL2_mixer.framework ~/Library/Frameworks/SDL2_ttf.framework
	@cp -R -i ./frameworks/SDL2.framework ./frameworks/SDL2_image.framework ./frameworks/SDL2_mixer.framework ./frameworks/SDL2_ttf.framework ~/Library/Frameworks

	$(CC) $(SDL) $(LIB) $^ $(OUT_OPT) $(NAME) $(PTHREAD) $(OPTIMA)

clean:
	$(RMF) $(addprefix $(OBJ_DIR), $(OBJ))
	$(RMD) $(OBJ_DIR)
	cd $(LIB_DIR) && $(MAKE) clean
	cd $(JSN_DIR) && $(MAKE) clean

fclean: clean
	$(RMF) $(NAME)
	cd $(LIB_DIR) && $(MAKE) fclean
	cd $(JSN_DIR) && $(MAKE) fclean

re: fclean all
	cd $(LIB_DIR) && $(MAKE) re
	cd $(JSN_DIR) && $(MAKE) re