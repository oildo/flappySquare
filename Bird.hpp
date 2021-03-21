#ifndef DEF_BIRD
#define DEF_BIRD

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Bird : public GameObject
{
  public:
    Bird(float x, float y, float width, float height, float gravity, float maxVel, float jumpForce, float yMax);
    void jump();
    void update(float deltaTime);
    bool isColliding(sf::Vector2f pos, sf::Vector2f dim);
  private:
    float m_velocity; // vertical
    float m_gravity;
    float m_maxVel;
    float m_yMax;
    float m_jumpForce;

};



#endif
