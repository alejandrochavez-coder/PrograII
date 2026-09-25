#pragma once
#include <math.h>

typedef struct {
    double x, y;
} Vector2D;

//https://en.wikipedia.org/wiki/Rotation_matrix
inline Vector2D vector_rotate(Vector2D vector, double radians) {
    double angle_cos = cos(radians);
    double angle_sin = sin(radians);

    return (Vector2D) {
        (angle_cos * vector.x) - (angle_sin * vector.y),
        (angle_sin * vector.x) + (angle_cos * vector.y)
    };
}

inline double vector_length_squared(Vector2D vector) {
    return vector.x * vector.x + vector.y * vector.y;
}

inline double vector_length(Vector2D vector) {
    return sqrt(vector_length_squared(vector));
}

inline Vector2D vector_divide_number(Vector2D vector, double x) {
    return (Vector2D){vector.x / x, vector.y / x};
}

inline Vector2D vector_divide_vector(Vector2D a, Vector2D b) {
    return (Vector2D){a.x / b.x, a.y / b.y};
}

inline Vector2D vector_multiply(Vector2D vector, double x) {
    return (Vector2D){vector.x * x, vector.y * x};
}

inline Vector2D vector_normalize(Vector2D vector) {
    if (vector_length_squared(vector) == 0) {
        return vector;
    }

    return vector_divide_number(vector, vector_length(vector));
}

inline Vector2D vector_add(Vector2D a, Vector2D b) {
    return (Vector2D){a.x + b.x, a.y + b.y};
}

inline Vector2D vector_subtract(Vector2D a, Vector2D b) {
    return (Vector2D){a.x - b.x, a.y - b.y};
}

inline bool vector_is_normalized(Vector2D vector) {
    return std::abs(vector_length_squared(vector) - 1) < 0.000001;
}