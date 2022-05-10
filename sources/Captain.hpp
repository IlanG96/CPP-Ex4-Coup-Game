#include "Game.hpp"
#include "Player.hpp"

namespace coup{
class Captain : public Player
{
private:
/**
 * @brief the last player the captain stole from
 * 
 */
    Player* stole_from;
public:
    /**
     * @brief Using Player constructor
     */
    using Player::Player;
    ~Captain(){}

    /**
     * @brief block the steal player "p" did
     * player p return the 2 coins to the player he took them from.
     * 
     * @param p the thief player
     */
    void block(Player& p);

    /**
     * @brief steal 2 coins from player "p"
     * 
     * @param p the player you want to steal from 
     */
    void steal(Player& p);

    /**
     * @brief Get the stole from object
     * 
     * @return Player* 
     */
    Player*  get_stole_from(){return this->stole_from;}
    
    /**
     * @brief Set the stole from object
     * 
     * @param p 
     */
    void  set_stole_from(Player* p){this->stole_from=p;}

    /**
     * @brief return player role
     * 
     * @return std::string 
     */
    std::string role(){return "Captain";}
};

}
