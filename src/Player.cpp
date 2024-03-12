#include "Player.hpp"
#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"
#include "Room.hpp"
#include <string>
#include <random>
#include <time.h>


int rollDice(int max, int min)
{
    int dice;
    dice = rand() % (max - min + 1) + 1;
    return dice;
}
int Health = 10;
void Player::Start()
{
    m_character = 'P';
    
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
        int attack = rollDice(20, 0);

        if(attack >= 10)
        {
            room->ClearLocation(m_position + direction);
            printf("current health:%i", Health);
            
        }
        if(attack < 10)
        {
            Health -= 1;
            printf("health:%i\n", Health);
            
        }
    }
}
