#include "vec3.h"
#include <math.h>

#define TAN tan

#define ASPECT_RATIO 1
#define IMAGE_WIDTH 400
#define IMAGE_HEIGHT 400

typedef struct s_viewport
{
//	t_camera *cam;
	int width;
	int	height;
	t_num focal_length;
	t_vec3d center;
	t_vec3d **rays;

}	t_viewport;

int main()
{
	t_num focal_length = 1.0;
	t_num foc = 90;
	t_num	viewport_width = 2 * TAN(foc / 2);
	t_num	viewport_height = viewport_width;
  t_vec3d	camera_center = (t_vec3d){0, 0, 0};

  viewport_u = vec3(viewport_width, 0, 0);
	viewport_v = vec3(0, -viewport_height, 0);

	pixel_delta_u = viewport_u / image_width;
	pixel_delta_v = viewport_v / image_height;

  // Calculate the location of the upper left pixel.
	viewport_upper_left = camera_center - vec3(0, 0, focal_length) \
		- viewport_u/2 - viewport_v/2;
	pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

}
