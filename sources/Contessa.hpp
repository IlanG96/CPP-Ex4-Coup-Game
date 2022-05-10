#include "Game.hpp"
#include "Player.hpp"

namespace coup{
class Contessa : public Player
{

public:
    /**
     * @brief Using Player constructor
     * 
     */
    using Player::Player;
    ~Contessa(){}

    /**
     * @brief block a coup made by an assassin.
    * 
    * @param p return player "p" back to the game.
    */
    void block(Player& p);

    /**
     * @brief return player role
     * 
     * @return std::string 
     */
    std::string role(){return "Contessa";}
};

}
