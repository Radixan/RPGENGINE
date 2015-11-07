
#ifndef __TRAINER_HPP__
#define __TRAINER_HPP__

#include "AbstractSprite.hpp"
#include "Pokemon.hpp"
#include "Inventory.hpp"

class Trainer {
  private:
    AbstractSprite      m_battleSprite;
    AbstractSprite      m_sprite;
    Pokemon             m_team[6];
    Inventory           m_inventory;

  public:

}

#endif // __TRAINER_HPP__
