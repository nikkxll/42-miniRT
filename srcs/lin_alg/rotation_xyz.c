#include "../../includes/structs.h"
#include "../../includes/vec3.h"

t_num	distance(t_vec3d p1, t_vec3d p2)
{
	t_num	d;

	d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
	return (d);
}

t_vec3d	vec_rot_x(t_vec3d vec, t_num angle)
{
	t_vec3d	row1;
	t_vec3d	row2;
	t_vec3d	row3;
	t_vec3d	rotated;
	t_num	angle_rad;

	angle_rad = angle * PI / 180;
	row1 = (t_vec3d){1, 0, 0};
	//row2 = (t_vec3d){0, cos(angle_rad), -sin(angle_rad)};
	//row3 = (t_vec3d){0, sin(angle_rad), cos(angle_rad)};
	row2 = (t_vec3d){0, cos(angle_rad), sin(angle_rad)};
	row3 = (t_vec3d){0, -sin(angle_rad), cos(angle_rad)};
	rotated.x = vec.x * row1.x + vec.y * row1.y + vec.z * row1.z;
	rotated.y = vec.x * row2.x + vec.y * row2.y + vec.z * row2.z;
	rotated.z = vec.x * row3.x + vec.y * row3.y + vec.z * row3.z;
	return (rotated);
}

t_vec3d	vec_rot_y(t_vec3d vec, t_num angle)
{
	t_vec3d	row1;
	t_vec3d	row2;
	t_vec3d	row3;
	t_vec3d	rotated;
	t_num	angle_rad;

	angle_rad = angle * M_PI / 180;
	//row1 = (t_vec3d){cos(angle_rad), 0, sin(angle_rad)};
	row1 = (t_vec3d){cos(angle_rad), 0, -sin(angle_rad)};
	row2 = (t_vec3d){0, 1, 0};
	//row3 = (t_vec3d){-sin(angle_rad), 0, cos(angle_rad)};
	row3 = (t_vec3d){sin(angle_rad), 0, cos(angle_rad)};
	rotated.x = vec.x * row1.x + vec.y * row1.y + vec.z * row1.z;
	rotated.y = vec.x * row2.x + vec.y * row2.y + vec.z * row2.z;
	rotated.z = vec.x * row3.x + vec.y * row3.y + vec.z * row3.z;
	return (rotated);
}

t_vec3d	vec_rot_z(t_vec3d vec, t_num angle)
{
	t_vec3d	row1;
	t_vec3d	row2;
	t_vec3d	row3;
	t_vec3d	rotated;
	t_num	angle_rad;

	angle_rad = angle * M_PI / 180;
	//row1 = (t_vec3d){cos(angle_rad), -sin(angle_rad), 0};
	//row2 = (t_vec3d){sin(angle_rad), cos(angle_rad), 0};
	row1 = (t_vec3d){cos(angle_rad), sin(angle_rad), 0};
	row2 = (t_vec3d){-sin(angle_rad), cos(angle_rad), 0};
	row3 = (t_vec3d){0, 0, 1};
	rotated.x = vec.x * row1.x + vec.y * row1.y + vec.z * row1.z;
	rotated.y = vec.x * row2.x + vec.y * row2.y + vec.z * row2.z;
	rotated.z = vec.x * row3.x + vec.y * row3.y + vec.z * row3.z;
	return (rotated);
}
