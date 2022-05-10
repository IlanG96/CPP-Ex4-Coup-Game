#include "Game.hpp"
#include "Player.hpp"

namespace coup{
class Assassin: public Player 
{
private:
    /**
     * @brief The last player the Assassin killed.
     * 
     */
     Player* last_coup;
public:
    /**
     * @brief Using Player constructor
     * 
     */
    using Player::Player;
    ~Assassin(){}

    /**
     * @brief Kill player "p".(delete him from the game).
     * cost 7 coins for assassin role it cost 3.
     * 
     * @param p the player you with to kill.
     */
    void coup(Player &p);
    
    /**
     * @brief Get the last coup object
     * 
     * @return Player* 
     */
    Player*  get_last_coup(){return this->last_coup;}

    /**
     * @brief return player role
     * 
     * @return std::string 
     */ 
    std::string role(){return "Assassin";}
};
}