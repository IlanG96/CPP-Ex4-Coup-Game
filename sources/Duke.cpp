#include <iostream>
#include <stdexcept>
#include <vector>
#include "Duke.hpp"
using namespace std;


namespace coup{

void Duke::tax(){
    if(static_cast<int>(this->curr_game->check_turn(this))!=1){
        throw std::runtime_error ("It's Not your turn");}
    if (Check_MaxCoins()){
        throw runtime_error("You have more then 10 coins you must use coup");}
    this->change_player_coins(3);
        this->Set_last_action("tax");
   this->curr_game->next_turn();     
}



void Duke::block(Player& p){ 
    this->Set_last_action("block");
    if (p.Get_last_action()=="foreign_aid")
    {
        p.change_player_coins(-2);
    }
    else{
        throw runtime_error("Duke can only block foreign aid.");
    }
}

Duke::~Duke(){}
}
