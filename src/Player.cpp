#include "Player.hpp"
#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"
#include "Room.hpp"
#include <string>
#include "Entity.hpp"
#include "Goblin.hpp"

//stats

void Player::Start()
{
    m_character = 'P';
    stats.constitution = 10.0f;
    stats.dexterity = 10.0f;
    stats.minHealth = 10.0f;
    stats.strength = 10.0f;
    stats.health = stats.minHealth;
    stats.gold = rollDice(3,0);
    
}
void Player::Update()
{
    // direction
    std::string instruction = "wasd and Enter to move";
    char directionInput = 'r';
    Vector2D direction(0.0f, 0.0f);

    while(directionInput != 'w' &&
          directionInput != 'a' &&
          directionInput != 's' &&
          directionInput != 'd')
    {
        directionInput = request_char(instruction.c_str());
    }

    if (directionInput == 'w')
        direction = Vector2D(0.0f, -1.0f);
    if (directionInput == 'a')
        direction = Vector2D(-1.0f, 0.0f);
    if (directionInput == 's')
        direction = Vector2D(0.0f, 1.0f);
    if (directionInput == 'd')
        direction = Vector2D(1.0f, 0.0f);
    
    // check for key
    if (room->GetLocation(m_position + direction) == 'K')
    {
        m_keyCount++;
        room->ClearLocation(m_position + direction);
    }

    // check for lock
    if (room->GetLocation(m_position + direction) == 'L')
    {
        if (m_keyCount <= 0)
            return;
        
        m_keyCount--;
        room->OpenDoor(m_position + direction);
    }

    // check for door
    if (room->GetLocation(m_position + direction) == 'D')
    {
        room->OpenDoor(m_position + direction);
    }
    //battle enemy
    if (room->GetLocation(m_position + direction) == 'V' || room->GetLocation(m_position + direction) == 'G')
    {  
        std::vector<Enemy> &enemies = room->GetMonsters();

        for(int x = 0; x < enemies.size(); x++)
        {
            if(enemies[x].pos == m_position + direction)
            {
                float enemyDex = enemies[x].stats.dexterity;
                float enemyStr = enemies[x].stats.strength;
                float enemyHealth = enemies[x].stats.health;
                float enemyDmg = enemies[x].stats.dmg;
                int enemyGold = enemies[x].stats.gold;
                
                
                Attack(stats.dexterity, stats.strength);
                printf("player Stats\n str %f\n dex %f\n dmg %f\n health %f\n hit %f\n", stats.strength, stats.dexterity, stats.dmg, stats.health, stats.hit);

                if(enemyDex < stats.hit)
                {
                    enemyHealth -= stats.dmg;
                    stats.hit = 0.0f;

                    
                } 
                
                enemies[x].Attack(enemyDex, enemyStr);
                printf("Enemy Stats\n str %f\n dex %f\n dmg %f\n health %f\n hit %f\n", enemyStr, enemyDex, enemyDmg, enemyHealth, enemies[x].stats.hit);
                if(stats.dexterity < enemies[x].stats.hit)
                {
                    stats.health -= enemyDmg;
                }
                enemies[x].stats.hit = 0.0f;

                
                if(stats.health > 0)
                {
                    printf("Your health is %f\n", stats.health);
                }
                if(stats.health <= 0)
                {
                    printf("You Died");
                    room->ClearLocation(m_position);
                }
                if(enemyHealth > 0)
                {
                    printf("Enemies health is %f\n", enemyHealth);
                }
                if(enemyHealth <= 0)
                {
                    room->ClearLocation(enemies[x].pos);
                    stats.gold += enemyGold;
                    printf("You got %i gold\n Total gold %i\n", enemyGold, stats.gold);
                }
                
            }
        }
    }
            // try to move
    if (room->GetLocation(m_position + direction) == ' ')
    {
        m_position += direction;
    }
    
}
