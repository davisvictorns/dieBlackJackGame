/* 
string nickname;
    int score;
    int played;
public:
    Player(string nickname);
    void setNickname(string nickname);
    string getNickname();
    void setPlayed(int played);
    int getPlayed();
 */

#include "Player.h"

Player::Player(string nickname_):nickname(nickname_), score(0), eliminated(0){}

void Player::setNickname(string nickname_){
    nickname = nickname_;
}

void Player::setScore(int score_){
    score = score_;
}

void Player::setEliminated(int eliminated_){
    eliminated = eliminated_;
}

string Player::getNickname(){
    return nickname;
}

int Player::getScore(){
    return score;
}

int Player::getEliminated(){
    return eliminated;
}