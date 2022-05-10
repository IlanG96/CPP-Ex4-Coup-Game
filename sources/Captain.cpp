#include <iostream>
#include <stdexcept>
#include <vector>
#include "Captain.hpp"
using namespace std;

namespace coup{

void Captain::block(Player& p){
    this->Set_last_action("block");
    if (p.Get_last_action()=="steal")
    {
        Captain *captain_cast = dynamic_cast<Captain*>(&p);
        captain_cast->change_player_coins(-2);
        captain_cast->get_stole_from()->change_player_coins(2);
        captain_cast->set_stole_from(NULL);
    }
    else{
        throw runtime_error("Captain can only block steal.");
    }
}

void Captain::steal(Player& p){
    if(static_cast<int>(this->curr_game->check_turn(this))!=1){
        throw std::runtime_error ("It's Not your turn");}
    if (Check_MaxCoins()){
        throw runtime_error("You have more then 10 coins you must use coup");}    
    this->Set_last_action("steal");
    if (p.coins()>=2)
    {
        p.change_player_coins(-2);
        this->change_player_coins(2);
        this->set_stole_from(&p);
    }
    else if(p.coins()==1){
        p.change_player_coins(-1);
        this->change_player_coins(1);
        this->set_stole_from(&p);
    }
    else{
        throw std::runtime_error (p.Get_player_name()+" has less then 2 coins");
    }
    this->curr_game->next_turn();
}
}