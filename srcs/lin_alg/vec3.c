//#include <math.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_vec3
{
	float x;
	float y;
	float z;
}	t_vec3;

typedef struct s_sphere
{
	float d;
	float r[3];
	float c[3];
	t_vec3 rr;
}	t_sphere;

float take_x(float r[3])
{
	return (r[0]);
}

int main()
{
	t_sphere s;
	t_sphere *ps;
	float r2[2];

	ps = malloc(sizeof(*ps));
	ps->r[0] = 3;
	ps->rr.x = 5;
	printf("x=%f\n", ps->r[0]);
	printf("x=%f\n", ps->rr.x);
	printf("x=%f\n", take_x(ps->r));
	printf("x=%f\n", take_x(r2));

	s.r[0] = 3;
	s.rr.x = 5;
	printf("x=%f\n", s.r[0]);
	printf("x=%f\n", s.rr.x);


	return (1);
}
