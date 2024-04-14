//
// Created by Andrew on 3/4/2024.
//

#include "projectile.h"
#include "environment.h"

Projectile::Projectile(Tuple pos, Tuple vel)
    : position_(pos), velocity_(vel.Normalize())
{
}

Projectile Projectile::Tick(Environment env, Projectile proj)
{
    Tuple position = proj.position_ + proj.velocity_;
    Tuple velocity = proj.velocity_ + env.GetGravity() + env.GetWind();
    return Projectile(position, velocity);
}
