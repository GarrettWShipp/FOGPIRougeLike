#pragma once

#include "Enemy.hpp"

class Goblin : public Enemy
{
public:
    float str = 0.0f;
    float dex = 0.0f;
    float con = 0.0f;
    float minHealth = 0.0f; //minium starting health
    float hit = 0.0f;
    float dmg = 0.0f;
    int health = 0;
    int gold = 0;
    void Start();
    void Update();
};