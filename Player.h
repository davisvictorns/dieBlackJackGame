#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
using namespace std;

class Player{
    private:
        string nickname;
        int score;
        int eliminated;
    public:
        Player(string nickname);
        void setNickname(string nickname);
        string getNickname();
        void setScore(int score);
        int getScore();
        void setEliminated(int eliminated);
        int getEliminated();
};

#endif