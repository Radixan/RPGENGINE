
#ifndef __TESTSCENE_HPP__
#define __TESTSCENE_HPP__

#include "AbstractScene.hpp"
#include "AbstractSprite.hpp"
#include "AbstractVisibleMap.hpp"
#include "Game.hpp"
#include "Tileset.hpp"
#include "Map.hpp"
#include "World.hpp"

class TestScene : public AbstractScene {
  private:
    Game*               m_game;
    int                 m_num;
    AbstractSprite      m_sprite;
    AbstractSprite      m_test;
    AbstractVisibleMap  m_map;
    AbstractVisibleMap  m_mapBack;
    Tileset             m_tileset;
  //  Map                 m_palletTown;
  //  Map                 m_palletTown2;
  //  Map*                m_mapa;
    World               m_world;

  public:

    TestScene(Game* game);

    void            Init            ();
    void            Update          ();
    void            Render          ();
    void            Delete          ();

    ~TestScene                      ();
};

#endif // __TESTSCENE_HPP__
