#include <iostream>
#include <stdexcept>
#include <vector>
#include "Ambassador.hpp"
#include "Captain.hpp"

using namespace std;

namespace coup{
void Ambassador::transfer(Player& from,Player& to){
    if(static_cast<int>(this->curr_game->check_turn(this))!=1){
        throw std::runtime_error ("It's Not your turn");}
    if (Check_MaxCoins()){
        throw runtime_error("You have more then 10 coins you must use coup");}
    this->Set_last_action("transfer");
    if (from.coins()>1)
    {
        from.change_player_coins(-1);
        to.change_player_coins(1);
    }
    else{
        throw std::runtime_error ("The player has 0 coins");
    }
    this->curr_game->next_turn();
}

void Ambassador::block(Player& p){
    this->Set_last_action("block");
    if (p.Get_last_action()=="steal")
    {
        Captain *captain_cast = dynamic_cast<Captain*>(&p);
        captain_cast->change_player_coins(-2);
        captain_cast->get_stole_from()->change_player_coins(2);
        captain_cast->set_stole_from(NULL);
    }
    else{
        throw runtime_error("Ambassador can only block steal.");
    }
}
}