#include "math_functions.h"
#include <cmath>

bool FloatEquality(float a, float b) {
    return fabsf(a - b) < EPSILON;
}

