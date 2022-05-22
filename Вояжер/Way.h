#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Way {
public:
    Way() {}
    virtual void Draw(sf::RenderWindow& window) = 0; 
};
