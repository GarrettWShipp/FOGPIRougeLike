#include "Enemy.hpp"
#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"
#include "Room.hpp"
#include <string>
#include "Stats.hpp"



void Enemy::Start()
{

    m_character = 'G';
    stats.constitution = 10.0f;
    stats.dexterity = 10.0f;
    stats.maxHealth = 10.0f;
    stats.strength = 10.0f;
    
}
