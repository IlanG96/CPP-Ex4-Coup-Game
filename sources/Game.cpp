#include "Game.hpp"
#include "Player.hpp"
#include <string>
#include <vector>
#include <iostream>

const int MAX_PLAYERS=6;
const int MIN_Players=2;

using namespace std;

namespace coup{
uint Game::turn_counter=0;
int Game::id_generator=0;

void Game::add_player(Player* p){
    if (players_list.size()+1>MAX_PLAYERS)
    {
        throw runtime_error("Max player capacity is 6");
    }
    if (game_started)
    {
        throw runtime_error("Cant add players when the game started");
    }
    
    p->Set_ID(id_generator++);
    this->players_list.push_back(p);
    if (this->players_list.size()==1)
    {
        p_turn=p;
    }
    active_players++;
}

void Game::delete_player(Player* p){
    for (uint i = 0; i < players_list.size(); i++)
    {
            if (players_list.at(i)==p)
            {
                players_list.at(i)->Set_Alive(false);
                players_list.at(i)=nullptr;
                active_players--;
            }    
    }
}

void Game::revive_player(Player* p){
    if (!p->Get_Alive_status())
    {
        players_list.at((uint)p->Get_ID())=p;
        p->Set_Alive(true);
        active_players++;
    }
    else{
        throw runtime_error(p->Get_player_name() +" already alive");
    }
}

void Game::next_turn(){
    if (!game_started)
    {
        game_started=true; //start the game
    }
    
    turn_counter=(turn_counter+1)%players_list.size(); //proceed to the next player

    while (players_list.at(turn_counter)==nullptr) //if the next player is eliminated continue to the next player alive
    {
        turn_counter=(turn_counter+1)%players_list.size();
    }
    p_turn=players_list.at(turn_counter);  
}

bool Game::check_turn(Player* p){
    if (players_list.size()<MIN_Players)
    {
        throw runtime_error("Cant start a game with 1 player");
    }        
    return (p==p_turn);
}

string Game::turn()const{
    return this->p_turn->Get_player_name();
}

string Game::winner(){
    if (active_players==1&&game_started)
    {
        for (uint i = 0; i < players_list.size(); i++)
        {
            if (players_list.at(i)!=nullptr)
            {
                game_started=false;
                return players_list.at(i)->Get_player_name();
            }
            
        }
        
    }
        throw runtime_error("Game is not over");
    
}

vector<string> Game::players()const{
    vector<string> player;
    int i=0;
    for (uint i = 0; i < players_list.size(); i++)
    {
        if (players_list.at(i)!=nullptr)
        {
            player.push_back(players_list.at(i)->Get_player_name());
        }  
    }
    
    return player;
}
}
