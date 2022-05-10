
#include <vector>
#include <string>
#ifndef GAME_H
#define GAME_H


namespace coup{
    class Player;
class Game
{
/**
 * @brief 
 * turn_counter - help turn function to select the player turn
 * id_generator - give each player an ID         
 * active_players - number of active players in game
 * p_turn - point to the player that need to play next
 * players_list - list of all the players in the game
 * game_started - true if game is started, false if not.
 */    
private:
    static uint turn_counter;
    static int id_generator;
    int active_players;
    Player* p_turn;
    std::vector<Player*> players_list;
    bool game_started;

public:
    /**
    * @brief Construct a new Game object
    * 
    */
    Game(){active_players=0;
           game_started=false;}
    ~Game(){turn_counter=0;
            id_generator=0;}
    /************************************/
      
    /**
     * @brief function that control whos turn is to play.
     * iterate over the players list and with the help of "turn_counter" change the "p_turn" to the next player in line.
     * 
     */
    void next_turn();

    /**
     * @brief Check if its player "p" turn to play
     * 
     * @param p player who want to know if it's his turn
     * @return true - if its player "p" turn
     * @return false - if its nor player "p" turn
     */
    bool check_turn(Player* p);

    /**
     * @brief add player "p" to the game only if the game didnt start already!
     */
    void add_player(Player* p);

    /**
     * @brief delete player "p" from the game.
     * happens only after the use of "coup"
     */
    void delete_player(Player* p);

    /**
     * @brief return player "p" to the game.
     * happens only after a block was made to a "coup" action
     */
    void revive_player(Player* p);
    
    /**
     * @brief return a vector with the names of all the active players in the game.
     * 
     * @return std::vector<std::string> - all the names of the players alive in game.
     */
    std::vector<std::string> players()const;

    /**
     * @brief return a string with the name of the player whose turn it is to play
     * @return turn it is to play
     */
    std::string turn()const;

    /**
     * @brief return the name of the winner of the game.
     * only if the game is finished.
     * @return winner name
     */
    std::string winner();
};

}
#endif