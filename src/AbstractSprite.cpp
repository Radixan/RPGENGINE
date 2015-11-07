
#include "AbstractSprite.hpp"

void AbstractSprite::load (const std::string filename) {
    this->m_texture.loadFromFile(filename);
    this->m_sprite.setTexture(this->m_texture);
    this->m_speed = 0;
    this->m_speed_ = 0;
    this->m_frames.clear();
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
  if (this->m_frames.size() > 0) {
    if (this->m_speed != 0) {
      this->m_speed_++;
      if (this->m_speed_ >= this->m_speed) {
        this->m_speed_ = 0;
        this->m_actualFrame = (this->m_actualFrame++) % this->m_frames.size();
        this->setIndex(this->m_actualFrame);
      }
    }
  }
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

void AbstractSprite::setSpeed (unsigned int speed) {
  this->m_speed = speed;
}

void AbstractSprite::setFrames (std::vector<int> frames) {
  this->m_actualFrame = 0;
  for (int i = 0; i < frames.size(); i++) {
    this->m_frames.push_back(frames.at(i));
  }
}
