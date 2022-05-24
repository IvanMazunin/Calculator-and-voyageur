#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Graph.h"

using namespace std;
using namespace sf;

class Node{
private:
    char c; 
    int x; 
    int y;
    sf::CircleShape circle; 
    int radius; 
    Font font; 
    Text text; 

    void Config() {
        circle.setRadius(radius);
        circle.setPosition(x - radius, y - radius);
        circle.setFillColor(sf::Color(139, 69, 19));

        font.loadFromFile("Bahnschrift.ttf");
        text.setFillColor(sf::Color::White);
        text.setString(c);
        text.setFont(font);
        text.setCharacterSize(radius);
        text.setOutlineColor(Color::White);
        text.setPosition(x - 0.55 * text.getGlobalBounds().width, y - 0.9 * text.getGlobalBounds().height);
    }
public:
    Node() {}

    Node(char c, int radius, int x, int y) {
        this->c = c;
        this->radius = radius;
        this->x = x;
        this->y = y;
    }
   
    Node(const Node& node) {
        this->c = node.c;
        this->radius = node.radius;
        this->x = node.x;
        this->y = node.y;
    }
    int GetRadius() {
        return radius;
    }
    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }
    void Draw(sf::RenderWindow& window) {
        Config();
        window.draw(this->circle);
        window.draw(this->text);
    }
};
