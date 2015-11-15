
#ifndef __TESTSCENE_HPP__
#define __TESTSCENE_HPP__

#include "AbstractScene.hpp"
#include "AbstractSprite.hpp"
#include "AbstractVisibleMap.hpp"
#include "Game.hpp"
#include "Tileset.hpp"
#include "Map.hpp"

class TestScene : public AbstractScene {
  private:
    Game*               m_game;
    int                 m_num;
    AbstractSprite      m_sprite;
    AbstractVisibleMap  m_map;
    AbstractVisibleMap  m_mapBack;
    Tileset             m_tileset;
    Map                 m_palletTown;

  public:

    TestScene(Game* game);

    void            Init            ();
    void            Update          ();
    void            Render          ();
    void            Delete          ();

    ~TestScene                      ();
};

#endif // __TESTSCENE_HPP__
