#include "core/game.h"

int main(int argc, char* argv[])
{
    Game *game = new Game();
    
    if (!game->initialize()){
        return -1;
    }

    game->run();

    delete game;    

    return 0;
}

