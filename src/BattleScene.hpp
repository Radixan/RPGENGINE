#include "AbstractScene.hpp"

#ifndef __BATTLESCENE_HPP__
#define __BATTLESCENE_HPP__

#include "Game.hpp"
#include "Battle.hpp"

class BattleScene : public AbstractScene {
  private:
    Game*       m_game;
    Battle*     m_battle;

  public:

    BattleScene(Game* game, Battle* battle);

    void       Update     ();
    void       Render     ();

    ~BattleScene();

};

#endif // __BATTLESCENE_HPP__
