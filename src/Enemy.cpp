#include "Room.hpp"

#include "Enemy.hpp"
#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"

#include <string>
#include "Stats.hpp"
#include "Player.hpp"
#include "Entity.hpp"
void Enemy::Start()
{
    //SetCharacter('G');
    m_character = 'G';
    stats.constitution = rollDice(6,0);
    stats.dexterity = 10.0f;
    stats.minHealth = 10.0f;
    stats.strength = 3.0f;
    stats.health = stats.minHealth;
    stats.dmg = 2.0f;
    stats.hit = 0.0f;
    stats.gold = rollDice(10, 1);
}
void Enemy::Update()
{
    
}