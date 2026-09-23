#include "vector2d.h"

namespace ik {

typedef struct Instance_T* Instance;

Instance create_instance();

void print(Instance instance);

void destroy_instance(Instance instance);

}