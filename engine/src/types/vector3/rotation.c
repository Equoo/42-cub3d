
#include "types/vector3.h"

t_vec3	rot_forward(t_rot r)
{
	const float	rad = M_PI / 180.0f;
	t_vec3		rot;

	rot.x = cosf(r.z * rad) * cosf(r.y * rad);
	rot.y = sinf(r.z * rad) * cosf(r.y * rad);
	rot.z = sinf(r.y * rad);
	return (rot);
}

t_vec3	rot_up(t_rot r)
{
	const float	rad = M_PI / 180.0f;
	t_vec3		rot;

	rot.x = cosf(r.z * rad) * sinf(r.x * rad);
	rot.y = sinf(r.z * rad) * sinf(r.x * rad);
	rot.z = cosf(r.x * rad);
	return (rot);
}

t_vec3	rot_right(t_rot r)
{
	const float	rad = M_PI / 180.0f;
	t_vec3		rot;

	rot.x = sinf(r.z * rad * cosf(r.x * rad));
	rot.y = cosf(r.z * rad * cosf(r.x * rad));
	rot.z = sinf(r.x * rad);
	return (rot);
}

