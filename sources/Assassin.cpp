#include <iostream>
#include <stdexcept>
#include <vector>
#include "Assassin.hpp"
using namespace std;
const int SEVEN=7;

namespace coup{
void Assassin::coup(Player& p){
    if(static_cast<int>(this->curr_game->check_turn(this))!=1){
        throw std::runtime_error ("It's Not your turn");}
    if (!p.Get_Alive_status())
    {
        throw runtime_error(p.Get_player_name()+" is already dead ");
    }
        
    if (this->coins()>=3&&this->coins()<SEVEN)
    {   this->Set_last_action("coup(3)");
        this->last_coup=&p;
        this->curr_game->delete_player(&p);
        this->change_player_coins(-3);
        cout<<p.Get_player_name()<<" is eliminated"<<endl;
    }
    else if(this->coins()>=SEVEN){
       this->Set_last_action("coup");
        this->last_coup=&p;
        this->curr_game->delete_player(&p);
        this->change_player_coins(-SEVEN);
        cout<<p.Get_player_name()<<" is eliminated"<<endl;
    }
    else{
        throw std::runtime_error ("You need 3 coins or more");
        return;
    }
    this->curr_game->next_turn();
}


}