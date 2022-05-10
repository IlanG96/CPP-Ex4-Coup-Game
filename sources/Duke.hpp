#include "Game.hpp"
#include "Player.hpp"
namespace coup{
class Duke : public Player
{
public:
    /**
     * @brief Using Player constructor
     * 
     */
    using Player::Player;
    ~Duke();
    
    /**
     * @brief Take 3 coins
     * 
     */
    void tax();

    /**
     * @brief block foreign_aid from player "p"
     * player p return the 2 coins he took.
     * 
     * @param p the blocked player
     */
    void block(Player &p);

    /**
     * @brief return player role
     * 
     * @return std::string 
     */
    std::string role(){return "Duke";}

};
}