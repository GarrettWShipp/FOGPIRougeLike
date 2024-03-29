#pragma once

struct Stats
{
    float strength = 0.0f;
    float dexterity = 0.0f;
    float constitution = 0.0f;
    float minHealth = 0.0f + constitution;
    float health = 0.0f;
    float hit = 0.0f;
    float dmg = 0.0f;
    int gold = 0;
};