#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
    float str = 0.0f;
    float dex = 0.0f;
    float con = 0.0f;
    float minHealth = 0.0f; //minium starting health
    float hit = 0.0f;
    float dmg = 0.0f;
    int health = 0;
    bool isAttacking = false;
    int gold = 0;
    void Start();
    void Update();
private:
    int m_keyCount = 0;
};