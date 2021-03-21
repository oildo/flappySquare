#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

GameObject::GameObject(float x, float y, float width, float height): m_x(x), m_y(y), m_width(width), m_height(height){}
GameObject::GameObject(float x, float y, sf::Vector2f dim):m_x(x), m_y(y),m_width(dim.x), m_height(dim.y){}
GameObject::GameObject(sf::Vector2f pos, float width, float height):m_x(pos.x), m_y(pos.y), m_width(width), m_height(height){}
GameObject::GameObject(sf::Vector2f pos, sf::Vector2f dim):m_x(pos.x), m_y(pos.y), m_width(dim.x), m_height(dim.y){}


sf::Vector2f GameObject::getDim(){
  return sf::Vector2f(m_width, m_height);
}

sf::Vector2f GameObject::getPos(){
  return sf::Vector2f(m_x, m_y);
}

void GameObject::setDim(float width, float height){
  m_width = width;
  m_height = height;
}
void GameObject::setDim(sf::Vector2f dim){
  m_width = dim.x;
  m_height = dim.y;
}
void GameObject::setPos(float x, float y){
  m_x = x;
  m_y = y;
}
void GameObject::setPos(sf::Vector2f pos){
  m_x = pos.x;
  m_y = pos.y;
}
void GameObject::move(float x, float y){
  m_x += x;
  m_y += y;
}
void GameObject::move(sf::Vector2f delta){
  m_x += delta.x;
  m_y += delta.y;
}
