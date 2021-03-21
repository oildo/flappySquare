#include "Pipe.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Pipe::Pipe(float x, float y, float width, float height, float offset, float speed, float yMax, float range):GameObject(x, y, width, height), m_offset(offset), m_speed(speed), m_yMax(yMax), m_initX(x), m_range(range){
  srand(time(NULL));
  reset();
}

sf::Vector2f Pipe::getDimBis(){
  return sf::Vector2f(m_width, m_yMax - m_offset - m_height);
}
sf::Vector2f Pipe::getPosBis(){
  return sf::Vector2f(m_x, m_height + m_offset);
}
void Pipe::update(float deltaTime){ //speed in px/sec
  m_x -= m_speed * deltaTime;
  if(m_x <= -m_width){
    m_x = m_initX;
    reset();
  }
}

void Pipe::reset(){
  m_height = rand()%(int)(m_yMax-2*m_range - m_offset) + m_range;
  
}
