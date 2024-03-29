#ifdef _WIN32
#include <windows.h>
#endif

#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"

#include "iostream"
#include "cstdlib"

#include "Room.hpp"
#include "Entity.hpp"

int main(int argc, char* argv[])
{
    srand(time(0));
    Room room;
    room.Load("assets/level_1.map");

    while(true)
    {
        room.Update();
    }

    return 0;
}