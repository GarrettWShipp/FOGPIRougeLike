#include "Entity.hpp"
#include "Room.hpp"
#include "Stats.hpp"
#include <random>
#include <time.h>

float Entity::Attack(float dex, float str)
{
    
    float hit = stats.hit = rollDice(dex, 0);
    float dmg = stats.dmg = rollDice(str, 1);
    return hit;
    return dmg;

}

int Entity::rollDice(int max, int min)
{
    int dice;
    dice = rand() % (max - min + 1) + 1;
    return dice;
}