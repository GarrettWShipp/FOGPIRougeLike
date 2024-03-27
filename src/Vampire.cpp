#include "Enemy.hpp"
#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"
#include "Room.hpp"
#include <string>
#include "Stats.hpp"
#include <random>
#include <time.h>


int rollDice(int max, int min)
{
    int dice;
    dice = rand() % (max - min + 1) + 1;
    return dice;
}

void Enemy::Start()
{
    m_character = 'V';
    stats.constitution = rollDice(9,0);
    stats.dexterity = 5.0f;
    stats.minHealth = 6.0f;
    stats.strength = 8.0f;
}

void Enemy::Update()
{
    //Attack
        //life steal

    //Health

    //Death
}
