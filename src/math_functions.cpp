#include "math_functions.h"
#include <cmath>

bool FloatEquality(const float a, const float b) {
    return fabsf(a - b) < EPSILON;
}

