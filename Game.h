#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Die.h"
using namespace std;

class Game{
    private:
        int players_count;
        int goal_score;
        int round;
        vector<Player> players;
        int order_now;
        int finished;
        int skip_count;
    public:
        Game();
        Game(int goal_score);
        void addPlayer(string nickname);
        void rollTheDie();
        void skipTurn();
        bool findPlayer(string nickname);
        int getAvailablePlayer();
        void checkGameHasFinished();
        int rollDies();
        int countAvailablePlayers();
        string getPlayerHighestScore();
};

#endif