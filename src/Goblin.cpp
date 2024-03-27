
#include "Room.hpp"

#include "Enemy.hpp"
#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"

#include <string>
#include "Stats.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "Goblin.hpp"

//stats
void Goblin::Start()
{
    
    m_character = 'G';
    con = stats.constitution = rollDice(6,0);
    dex = stats.dexterity = 8.0f;
    minHealth = stats.minHealth = 2.0f;
    str = stats.strength = 3.0f;
    health = stats.minHealth;
    dmg = stats.dmg;
    hit = stats.hit;
    gold = stats.gold = rollDice(10, 1);
}
void Goblin::Update()
{
    
}