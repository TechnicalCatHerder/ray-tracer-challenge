//
// Created by Andrew on 4/10/2024.
//
#pragma once
#include <tuple.h>

class Projectile;
class Environment;

class Cannon {

public:
    Cannon();
    ~Cannon() = default;

    Projectile LoadCannon(Tuple pos, Tuple vel);
    void FireCannon(Projectile ball, Environment env);
};
