
#ifndef CAMERA_H
# define CAMERA_H
# include "types/vector3.h"

typedef struct  s_camera {
    t_vec3  pos;
    t_vec3  rot;
    int     fov;
}   t_camera;

#endif
