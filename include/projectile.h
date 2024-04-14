#pragma once
#include "tuple.h"
#include "environment.h"

class Projectile {

    Tuple position_;
    Tuple velocity_;

public:
    Projectile(Tuple pos, Tuple vel);
    ~Projectile() = default;

    Tuple GetPosition() const { return position_; }
    Tuple GetVelocity() const { return velocity_; }

    Projectile Tick(Environment env, Projectile proj);

};