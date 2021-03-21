#ifndef DEF_PIPE
#define DEF_PIPE

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Pipe : public GameObject{
  public:
    Pipe(float x, float y, float width, float height, float offset, float speed, float yMax, float range);
    void update(float deltaTime);
    sf::Vector2f getDimBis();
    sf::Vector2f getPosBis();
    void reset();


  private:
    float m_offset;
    float m_speed;
    float m_yMax;
    float m_initX;
    float m_range;

};

#endif
