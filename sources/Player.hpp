#include <string>
#include "Game.hpp"

#ifndef PLAYER_H
#define PLAYER_H
namespace coup{


class Player
{
    /**
     * @brief 
     * _player_name - player name
     * _last_action - the last action the player did
     * Player_ID - player ID in game
     * curr_game - the current game the player is in
     */
private:
    std::string _player_name;
    std::string _last_action;
    int Player_ID;
    bool Alive;

protected:
    Game* curr_game;
    int _coins=0;  
public:
/**
 * @brief Construct a new Player object
 * 
 */
    Player(){}
    Player(Game &g,std::string  const &name);
    ~Player();
/*********************************************/


    /**
     * @brief Getters
    */
    std::string Get_player_name()const{return this->_player_name;}
    std::string Get_last_action()const{return this->_last_action;}
    int Get_ID()const{return Player_ID;}
    bool Get_Alive_status()const{return Alive;}

    /**
     * @brief Setters
     */
    void Set_player_name(std::string name){this->_player_name=name;}
    void change_player_coins(const int &amount){this->_coins+=amount;}
    void Set_last_action(std::string action){this->_last_action=action;}
    void Set_ID(int num){this->Player_ID=num;}
    void Set_Alive(bool status){this->Alive=status;}

    /**
     * @brief Check if the player has more then 10 coins.
     * 
     * @return true >10
     * @return false <10
     */
    bool Check_MaxCoins()const;

    /**
     * @brief Get 1 coin 
     */
    virtual void income();

    /**
     * @brief Get 2 coins
     */
    virtual void foreign_aid();

    /**
     * @brief Kill player "p".(delete him from the game).
     * cost 7 coins for assassin role it cost 3.
     * @param p the player you want to kill.
     */
    virtual void coup(Player& p);

    /**
     * @brief 
     * @return int - amount of coins the player has.
     */
    virtual int coins()const {return _coins;}

    /**
     * @brief 
     * @return std::string return the name of the role the player got.
     */
    virtual std::string role()const{return "Player";}
};

}
#endif