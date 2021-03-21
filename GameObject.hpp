#ifndef DEF_GAMEOBJECT
#define DEF_GAMEOBJECT

#include <SFML/Graphics.hpp>

class GameObject{

  public:
    GameObject(float x, float y, float width, float height);
    GameObject(float x, float y, sf::Vector2f dim);
    GameObject(sf::Vector2f pos, float width, float height);
    GameObject(sf::Vector2f pos, sf::Vector2f dim);
    sf::Vector2f getDim();
    sf::Vector2f getPos();
    void setDim(float width, float height);
    void setDim(sf::Vector2f dim);
    void setPos(float x, float y);
    void setPos(sf::Vector2f pos);
    void move(float x = 0.0f, float y = 0.0f);
    void move(sf::Vector2f delta);



  protected:
    float m_width;
    float m_height;
    float m_x;
    float m_y;

};



#endif
