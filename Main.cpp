#include <iostream>
#include <cstdlib>
#include "Game.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Game game;
    
    game.addPlayer("Davis");
    game.addPlayer("Victor");
    game.addPlayer("Nascimento");

    game.rollTheDie();
    game.rollTheDie();
    game.rollTheDie();
    
    game.rollTheDie();
    game.rollTheDie();
    game.rollTheDie();
    
    game.rollTheDie();
    game.rollTheDie();
    game.skipTurn();

    game.rollTheDie();
    game.skipTurn();
    game.rollTheDie();
    
    game.rollTheDie();
    game.rollTheDie();
    game.rollTheDie();
    
    game.rollTheDie();
    game.skipTurn();
    game.rollTheDie();

    game.rollTheDie();
    game.skipTurn();
    game.skipTurn();
    
    return 0;
}
