#include "Game.h"
#include <iostream> 
#include <ctime> 
#include <cstdlib>

Game::Game():players_count(0), goal_score(21), round(0), order_now(0), finished(0), skip_count(0){}
Game::Game(int goal_score_):players_count(0), goal_score(goal_score_), round(0), order_now(0), finished(0), skip_count(0){}

void Game::addPlayer(string nickname){
    if(finished == 0){
        bool already_exists = Game::findPlayer(nickname);
        
        if(already_exists){
            cout<<"The nickname '"<< nickname <<"' already exists, try another!"<<endl;
        }else{
            Player new_player(nickname);
            players.push_back(new_player);
            players_count++;
            cout<<"The player '"<< nickname <<"' was added to the game!"<<endl;
        }
    }else{
        cout<<"This game was already finished!"<<endl;
    }
}

void Game::rollTheDie(){
    if(finished == 0){
        if(order_now >= players_count){
            round++;
            skip_count = 0;
            order_now = 0;
        }

        int dies_value = Game::rollDies();
        
        order_now = Game::getAvailablePlayer();
        if(order_now == -1){
            cout<<"The game has finished! No players available!"<<endl;
        }else{
            int player_score = players[order_now].getScore();
            players[order_now].setScore(player_score + dies_value);
            player_score = players[order_now].getScore();

            if(player_score > goal_score){
                players[order_now].setEliminated(1);
                cout<<"The player '"<< players[order_now].getNickname() <<"' was eliminated. The goal was excedded ("<< player_score <<"/"<<goal_score<<")."<<endl;
                Game::checkGameHasFinished();
            }else if(player_score == goal_score){
                cout<<"The player '"<< players[order_now].getNickname() <<"' is the winner! The goal was reached ("<< player_score <<"/"<<goal_score<<")."<<endl;
                finished = 1;
            }else{
                cout<<"The player '"<< players[order_now].getNickname() <<"' rolled the die. His score now is ("<< player_score <<"/"<<goal_score<<")."<<endl;
            }
            
            order_now++;
        }
    }else{
        cout<<"This game was already finished!"<<endl;
    }
}

bool Game::findPlayer(string nickname){
    for(int i = 0; i < players_count; i++)
    {
        if(players[i].getNickname() == nickname)
            return true;
    }
    return false;
}

void Game::skipTurn(){
    if(finished == 0){
        
        if(order_now >= players_count){
            round++;
            skip_count = 0;
            order_now = 0;
        }
        
        order_now = Game::getAvailablePlayer();
        
        cout<<"The player '"<< players[order_now].getNickname() <<"' has skip. His score is ("<< players[order_now].getScore() <<"/"<<goal_score<<")."<<endl;
        order_now++;
        
        skip_count++;
        if (skip_count == Game::countAvailablePlayers()) {
            finished = 1;
            string player_highest_score = Game::getPlayerHighestScore();
            cout<<"All the players decided to skip, so the winner is '"<< player_highest_score <<"'"<<endl;
        }
        
    }else{
        cout<<"This game was already finished!"<<endl;
    }
}

int Game::getAvailablePlayer(){
    int twice = 0;
    if(players[order_now].getEliminated() == 0){
        return order_now;
    }else{
        while(players[order_now].getEliminated() == 1){
            order_now++;
            if(order_now >= players_count){
                round++;
                skip_count = 0;
                order_now = 0;
                twice++;
            }
            if(twice > 1){
                finished = 1;
                return -1;
            }
        }
        return order_now;
    }
}

void Game::checkGameHasFinished(){
    int count_eliminated = 0;

    for(int i = 0; i < players_count; i++)
    {
        if(players[i].getEliminated() == 1){
            count_eliminated++;
        }
    }

    if(count_eliminated == players_count){
        finished = 1;
        cout<<"The game has finished! No players available!"<<endl;
    }else if(count_eliminated == players_count-1){
        finished = 1;

        for(int i = 0; i < players_count; i++)
        {
            if(players[i].getEliminated() == 0){
                cout<<"The game has finished! "<< players[i].getNickname() <<" is the winner!"<<endl;
            }
        }   
    }
    
}

int Game::rollDies(){
    mt19937 generator;
    generator.seed(time(0));

    uniform_int_distribution<uint32_t> die(1, 6);
    
    int val1 = die(generator);
    int val2 = die(generator);

    return val1 + val2;
}

int Game::countAvailablePlayers(){
    int count = 0;
    for(int i = 0; i < players_count; i++)
    {
        if(players[i].getEliminated() == 0){
            count++;
        }
    }
    return count;
}

string Game::getPlayerHighestScore(){
    string player_highest_score;
    int highest_score = 0;

    for(int i = 0; i < players_count; i++)
    {
        if(players[i].getEliminated() == 0){
            if(players[i].getScore() > highest_score){
                highest_score = players[i].getScore();
                player_highest_score = players[i].getNickname();
            }
        }
    }
    
    return player_highest_score;
}