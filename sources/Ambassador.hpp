
#include "Game.hpp"
#include "Player.hpp"
namespace coup{
class Ambassador : public Player
{
public:
    /**
     * @brief Using Player constructor
     * 
     */
    using Player::Player;
    ~Ambassador(){}

    /**
     * @brief block the steal player "p" did
     * player p return the 2 coins to the player he took them from.
     * 
     * @param p the thief player
     */
    void block(Player& p);

    /**
     * @brief tranfer 1 coin from player 1 to player 2.
     * 
     * @param from - lose 1 coin
     * @param to - gain 1 coin
     */
    void transfer(Player& from,Player& to);

    /**
     * @brief return player role
     * 
     * @return std::string 
     */
    std::string role(){return "Ambassador";}
};
}
