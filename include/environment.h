#pragma once
#include "tuple.h"


class Environment {

    Tuple gravity_;
    Tuple wind_;

public:
    Environment(Tuple grav, Tuple wind);
    ~Environment() = default;

    Tuple GetGravity() const { return gravity_; }
    Tuple GetWind() const { return wind_; }

};