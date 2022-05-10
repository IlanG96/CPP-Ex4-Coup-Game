#include "Player.hpp"
#include <iostream>
using namespace std;
const int Coup_min_coins=7;
const int Max_coins=10;
namespace coup{
Player::Player(Game &g,string const &name){
        this->_player_name=name;
        this->curr_game=&g;
        this->Player_ID=0;
        this->curr_game->add_player(this);
        this->_coins=0;
        this->Alive=true;
        
    }

bool Player::Check_MaxCoins()const{
    return this->coins()>=Max_coins;
}

void Player::income(){
    if(static_cast<int>(this->curr_game->check_turn(this))!=1){
        throw runtime_error ("It's Not your turn");
        return;
    }
    if (Check_MaxCoins())
    {
        throw runtime_error("You have more then 10 coins you must use coup");
    }
    
    this->change_player_coins(1);
    this->Set_last_action("income");
    this->curr_game->next_turn();
}

void Player::foreign_aid(){
    if(static_cast<int>(this->curr_game->check_turn(this))!=1){
        throw runtime_error ("It's Not your turn");}
    if (Check_MaxCoins()){
        throw runtime_error("You have more then 10 coins you must use coup");}    
    this->change_player_coins(2);
    this->Set_last_action("foreign_aid");
    this->curr_game->next_turn();
}

void Player::coup(Player& p){
    if(static_cast<int>(this->curr_game->check_turn(this))!=1){
        throw runtime_error ("It's Not your turn");
        return;
    }
    if (!p.Get_Alive_status())
    {
        throw runtime_error(p.Get_player_name()+" is already dead ");
    }
    this->Set_last_action("coup");
    if (this->coins()>=Coup_min_coins)
    {
        this->curr_game->delete_player(&p);
        this->change_player_coins(-Coup_min_coins);
        cout<<p.Get_player_name()<<" is eliminated"<<endl;
        this->curr_game->next_turn();
    }
    else{
        throw runtime_error ("You need 7 coins or more");
        return;
    }
}
Player::~Player(){}


}