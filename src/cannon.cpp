//
// Created by Andrew on 4/10/2024.
//
#include "cannon.h"
#include "projectile.h"
#include "environment.h"
#include <iostream>


Cannon::Cannon()
{

}

Projectile Cannon::LoadCannon(Tuple pos, Tuple vel)
{
    return Projectile(pos, vel);
}

void Cannon::FireCannon(Projectile ball, Environment env)
{
    while (ball.GetPosition().GetY() > 0) {
        ball = ball.Tick(env, ball);
        std::cout << "The cannonball is at: " << ball.GetPosition().GetX() << ", "
                         << ball.GetPosition().GetY() << ", "
                         << ball.GetPosition().GetZ() << std::endl;
    }

}
