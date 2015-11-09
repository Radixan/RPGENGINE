
#ifndef __BATTLE_HPP__
#define __BATTLE_HPP__

#include "Trainer.hpp"

class Game;

class Battle {
  private:
    Trainer*       m_player;
    Trainer*       m_enemy;
    unsigned int   m_state;

    void      startingBattle ();

  public:

    Battle (Trainer* player, Trainer* enemy);
    void      update      ();
    void      render      (Game* game);

};

#endif // __BATTLE_HPP__
