#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Graph.h"
#include "Node.h"
#include "Way.h"

using namespace std;
using namespace sf;
const double PI = 3.141592653589793; 

class OneWay : public Way {
private:
    Node node1;
    Node node2; 
    int length; 
    sf::Color color; 
public:
    OneWay(const Node& node1, const Node& node2, int length, sf::Color color) {
        this->node1 = node1;
        this->node2 = node2;
        this->length = length;
        this->color = color;
    }

    void Draw(sf::RenderWindow& window) override {
        
        VertexArray line(sf::LinesStrip, 2);
        line[0].color = color;
        line[0].position.x = node1.GetX();
        line[0].position.y = node1.GetY();

        line[1].color = color;
        line[1].position.x = node2.GetX();
        line[1].position.y = node2.GetY();
        window.draw(line);

        double rotation = PI;
        if (node2.GetX() - node1.GetX() > 0)
            rotation = atan((double)(node2.GetY() - node1.GetY()) / (double)(node2.GetX() - node1.GetX())) + PI / 2;
        else if (node2.GetX() - node1.GetX() < 0)
            rotation = atan((double)(node2.GetY() - node1.GetY()) / (double)(node2.GetX() - node1.GetX())) - PI / 2;
        else if (node2.GetY() - node1.GetY() < 0)
            rotation = 0;

        int PosX = node2.GetX() - node2.GetRadius() * sin(rotation) - 10 * cos(rotation); 
        int PosY = node2.GetY() + node2.GetRadius() * cos(rotation) - 10 * sin(rotation); 

        sf::CircleShape tail(10, 3);
        tail.setRotation(180 * rotation / PI);
        tail.setPosition(PosX, PosY);
        tail.setFillColor(color);
        window.draw(tail);

        int TextX = ((node2.GetX() - node1.GetX()) / 3 + node1.GetX());
        int TextY = ((node2.GetY() - node1.GetY()) / 3 + node1.GetY());

        int size = 20;
        CircleShape c(size / 2, 300);
        c.setPosition(TextX - size / 2, TextY - size / 2);
        c.setFillColor(Color(70, 130, 180));
        window.draw(c);

        Font font;
        Text text;
        font.loadFromFile("Bahnschrift.ttf");
        text.setString(to_string(length));
        text.setFont(font);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(Color::White);
        text.setCharacterSize(size / 1.5);
        text.setPosition(TextX - text.getGlobalBounds().width / 2, TextY - text.getGlobalBounds().height);
        window.draw(text);
    }
};