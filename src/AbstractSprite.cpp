
#include "AbstractSprite.hpp"
#include <iostream>

void AbstractSprite::load (const std::string filename) {
  this->m_texture.loadFromFile(filename);
  this->m_sprite.setTexture(this->m_texture);
  this->m_frames.clear();
  this->m_time = sf::Time::Zero;
  this->m_playing = false;
}

void AbstractSprite::loadTexture (sf::Texture& texture) {
  this->m_texture = texture;
  this->m_sprite.setTexture(this->m_texture);
}

void AbstractSprite::render (Game* game) {
  game->getWindow().draw(this->m_sprite);
}

void AbstractSprite::setDimensions (uint16_t wide, uint16_t hight) {
  this->m_wide = wide;
  this->m_hight = hight;
}

void AbstractSprite::setOffsets (uint16_t x, uint16_t y) {
  this->m_offsetX = x;
  this->m_offsetY = y;
}

void AbstractSprite::setTextureDimensions (uint16_t wide, uint16_t hight) {
  this->m_textureWide = wide;
  this->m_textureHight = hight;
}

void AbstractSprite::update (sf::Time deltaTime) {
  if (this->m_frames.size() > 0) {
    this->m_currentTime += deltaTime;
    if (this->m_playing && this->m_currentTime >= this->m_time)  {
      // reset time, but keep the remainder
      this->m_currentTime = sf::microseconds(this->m_currentTime.asMicroseconds() % this->m_time.asMicroseconds());
      this->m_actualFrame += 1;
      this->m_actualFrame %= this->m_frames.size();
      this->m_time = this->m_frames.at(this->m_actualFrame).time;
    }
    this->setIndex(this->m_frames.at(this->m_actualFrame).frame);
  }
  this->m_sprite.setPosition(sf::Vector2f(m_x,m_y));
  this->m_sprite.setTextureRect(sf::IntRect(
                                this->m_offsetX, this->m_offsetY,
                                this->m_wide, this->m_hight));
}

void AbstractSprite::setIndex (uint16_t index) {
  this->m_offsetX = (index % (this->m_textureWide / this->m_wide)) * (this->m_wide);
  this->m_offsetY = (index / (this->m_textureWide / this->m_wide)) * (this->m_hight);
}

void AbstractSprite::setPosition (int16_t x, int16_t y) {
  this->m_x = x;
  this->m_y = y;
}

int AbstractSprite::getX() {
  return this->m_x;
}

int AbstractSprite::getY() {
  return this->m_y;
}

void AbstractSprite::setActualFrame(uint16_t frame) {
  this->m_actualFrame = this->m_frames.at(frame).frame;
  this->m_time = this->m_frames.at(frame).time;
}

void AbstractSprite::setSpeed (sf::Time frameTime) {
  this->m_time = frameTime;
}

void AbstractSprite::setFrames (std::vector<Animation> frames) {
  this->m_actualFrame = 0;
  for (unsigned int i = 0; i < frames.size(); i++) {
    this->m_frames.push_back(frames.at(i));
  }
}

void AbstractSprite::playAnimation () {
  this->m_playing = true;
}

void AbstractSprite::stopAnimation () {
  this->m_playing = false;
}
