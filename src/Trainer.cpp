
#include "Trainer.hpp"

Trainer::Trainer(AbstractSprite* battleSprite){
  this->m_battleSprite = battleSprite;
}

AbstractSprite* Trainer::getBattleSprite() {
  return this->m_battleSprite;
}
