#pragma once
#include "fogpi/Math.hpp"

#include <string>
#include <vector>

#include "Entity.hpp"
#include "Enemy.hpp"
#include "Door.hpp"

class Room {
public:
    void Load(std::string _path);
    void Draw();
    void Update();

    bool StillPlaying() { return true; }

    Entity& GetPlayer() { return *m_player; }
    std::vector<Enemy>& GetMonsters() { return m_enemy; }
    const std::vector<std::vector<char>>& GetMap() { return m_map; }
    char GetLocation(Vector2D _pos);
    void ClearLocation(Vector2D _pos);
    void OpenDoor(Vector2D _pos);
    
protected:
    Entity *m_player = nullptr;
    std::vector<std::vector<char>> m_map;
    std::vector<Door> m_doors;
    std::vector<Enemy> m_enemy;
};