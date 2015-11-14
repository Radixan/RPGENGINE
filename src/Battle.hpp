
#ifndef __BATTLE_HPP__
#define __BATTLE_HPP__

#include "Trainer.hpp"

class Game;

class Battle {
  private:
    Trainer*        m_player;
    Trainer*        m_enemy;
    uint8_t         m_state;

    void      startingBattle (sf::Time deltaTime);

  public:

    Battle (Trainer* player, Trainer* enemy);
    void      update      (sf::Time deltaTime);
    void      render      (Game* game);

};

#endif // __BATTLE_HPP__
