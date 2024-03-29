#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
    void Start();
    void Update();
private:
    int m_keyCount = 0;
};