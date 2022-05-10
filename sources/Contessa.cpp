#include <iostream>
#include <stdexcept>
#include <vector>
#include "Contessa.hpp"
#include "Assassin.hpp"

using namespace std;

namespace coup{
void Contessa::block(Player& p){
    this->Set_last_action("block");
    if (p.Get_last_action()=="coup(3)")
    {
        Assassin *Assassin_cast = dynamic_cast<Assassin*>(&p);
        curr_game->revive_player(Assassin_cast->get_last_coup());
    }
    else{
        throw runtime_error("Contessa can only block assassin coup.");
    }
}
}