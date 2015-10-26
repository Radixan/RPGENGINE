
#include "AbstractSprite.hpp"

void AbstractSprite::load (const std::string filename) {
    this->m_texture.loadFromFile(filename);
    this->m_sprite.setTexture(this->m_texture);
}

void AbstractSprite::loadTexture (sf::Texture& texture) {
    this->m_texture = texture;
    this->m_sprite.setTexture(this->m_texture);
}

void AbstractSprite::render (Game* game) {
  game->getWindow().draw(this->m_sprite);
}

void AbstractSprite::setDimensions (unsigned int wide, unsigned int hight) {
  this->m_wide = wide;
  this->m_hight = hight;
}

void AbstractSprite::setOffsets (unsigned int x, unsigned int y) {
  this->m_offsetX = x;
  this->m_offsetY = y;
}

void AbstractSprite::setTextureDimensions (unsigned int wide, unsigned int hight) {
  this->m_textureWide = wide;
  this->m_textureHight = hight;
}

void AbstractSprite::update () {
  this->m_sprite.setPosition(sf::Vector2f(m_x,m_y));
  this->m_sprite.setTextureRect(sf::IntRect(
                                this->m_offsetX, this->m_offsetY,
                                this->m_wide, this->m_hight));
}

void AbstractSprite::setIndex (unsigned int index) {
  this->m_offsetX = (index % (this->m_textureWide / this->m_wide)) * (this->m_wide);
  this->m_offsetY = (index / (this->m_textureWide / this->m_wide)) * (this->m_hight);
}

void AbstractSprite::setPosition (int x, int y) {
  this->m_x = x;
  this->m_y = y;
}
