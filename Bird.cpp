#include "Bird.hpp"
Bird::Bird(float x, float y, float width, float height, float gravity, float maxVel, float jumpForce, float yMax):GameObject(x, y, width, height), m_gravity(gravity), m_maxVel(maxVel), m_jumpForce(jumpForce), m_yMax(yMax - height){}

void Bird::update(float deltaTime){ // delta time in sec, velocity pix/sec

  m_velocity += m_gravity * deltaTime;
  if(m_velocity > m_maxVel)
    m_velocity = m_maxVel;

  m_y += m_velocity * deltaTime;

  if(m_y > m_yMax)
    m_y = m_yMax;
  else if(m_y < .0f){
    m_y = .0f;
    m_velocity = 0;
  }
}
void Bird::jump(){
  m_velocity = -m_jumpForce;
}

bool Bird::isColliding(sf::Vector2f pos, sf::Vector2f dim){
  return m_x < pos.x + dim.x &&
   m_x + m_width > pos.x &&
   m_y < pos.y + dim.y &&
   m_height + m_y > pos.y;
}
