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
    con = stats.constitution = 5.0f;
    dex = stats.dexterity = 5.0f;
    minHealth = stats.minHealth = 5.0f;
    str = stats.strength = 5.0f;
    health = stats.minHealth;
    gold = stats.gold = rollDice(3,0);
    
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

    // try to move
    if (room->GetLocation(m_position + direction) == ' ')
        m_position += direction;
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

                Attack(dex, str);
                if(enemyDex < hit)
                {
                    enemyHealth -= dmg;
                    hit = 0.0f;
                    
                } 
                enemies[x].Attack(enemyDex, enemyStr);
                {
                    health -= enemyDmg;
                    enemies[x].stats.hit = 0.0f;
                }
                if(health > 0)
                {
                    printf("Your health is %i\n", health);
                }
                if(health <= 0)
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
                    gold += enemyGold;
                    printf("You got %i gold\n", enemyGold);
                }
                
            }
        }
    }
}
