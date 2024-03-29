#include "Entity.hpp"
#include "Room.hpp"
#include "Stats.hpp"
#include <random>
#include <time.h>

void Entity::Attack(float dex, float str)
{
    stats.hit = rollDice(dex, 0);
    stats.dmg = rollDice(str, 1);
}

int Entity::rollDice(int max, int min)
{
    int dice;
    dice = rand() % (max - min + 1) + 1;
    return dice;
}