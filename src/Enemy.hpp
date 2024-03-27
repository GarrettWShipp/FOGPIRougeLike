#pragma once

#include "Entity.hpp"

class Enemy : public Entity
{
public:
    Vector2D pos;
    void Start();
    void Update();
    
    
};