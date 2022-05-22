#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include "Graph.h"
#include "Node.h"
#include "Way.h"

using namespace std;
using namespace sf;

class TwoWays : public Way {
private:
    Node node1; 
    Node node2; 
    int length1; 
    int length2; 
    Color color; 
public:
  
    TwoWays(const Node& node1, const Node& node2, int length1, int length2, Color color) {
        this->node1 = node1;
        this->node2 = node2;
        this->length1 = length1;
        this->length2 = length2;
        this->color = color;
    }

    void Draw(sf::RenderWindow& window) override {
   
        VertexArray line(sf::LinesStrip, 2);
        line[0].position.x = node1.GetX();
        line[0].position.y = node1.GetY();
        line[0].color = color;
        line[1].position.x = node2.GetX();
        line[1].position.y = node2.GetY();
        line[1].color = color;
        window.draw(line);

        
        double rotation = 0; 
        if (node2.GetX() - node1.GetX() > 0)
            rotation = atan((double)(node2.GetY() - node1.GetY()) / (double)(node2.GetX() - node1.GetX())) + PI / 2;
        else if (node2.GetX() - node1.GetX() < 0)
            rotation = atan((double)(node2.GetY() - node1.GetY()) / (double)(node2.GetX() - node1.GetX())) - PI / 2;
        else if (node2.GetY() - node1.GetY() > 0)
            rotation = PI;

        int PosX = (node1.GetX() + node2.GetX()) / 2; 
        int PosY = (node1.GetY() + node2.GetY()) / 2; 

        sf::CircleShape tail1(10, 3);
        tail1.setPosition(PosX - 10 * cos(rotation), PosY - 10 * sin(rotation));
        tail1.setRotation(180 * rotation / PI);
        tail1.setFillColor(color);
        window.draw(tail1);

        sf::CircleShape tail2(10, 3);
        tail2.setPosition(PosX + 10 * cos(rotation), PosY + 10 * sin(rotation));
        tail2.setRotation(180 * rotation / PI + 180);
        tail2.setFillColor(color);
        window.draw(tail2);

       
        int TextX1 = ((node2.GetX() - node1.GetX()) / 5 + node1.GetX());
        int TextY1 = ((node2.GetY() - node1.GetY()) / 5 + node1.GetY());
        int TextX2 = ((node1.GetX() - node2.GetX()) / 5 + node2.GetX());
        int TextY2 = ((node1.GetY() - node2.GetY()) / 5 + node2.GetY());

        int size = 25;
        CircleShape c1(size / 2, 300);
        c1.setPosition(TextX1 - size / 2, TextY1 - size / 2);
        c1.setFillColor(Color(70, 130, 180));
        window.draw(c1);
        CircleShape c2(size / 2, 300);
        c2.setPosition(TextX2 - size / 2, TextY2 - size / 2);
        c2.setFillColor(Color(70, 130, 180));
        window.draw(c2);

        Font font1;
        Text text1;
        font1.loadFromFile("Bahnschrift.ttf");
        text1.setString(to_string(length1));
        text1.setFont(font1);
        text1.setStyle(sf::Text::Bold);
        text1.setFillColor(Color::White);
        text1.setCharacterSize(size / 1.5);
        text1.setPosition(TextX1 - 0.55 * text1.getGlobalBounds().width, TextY1 - 0.9 * text1.getGlobalBounds().height);
        window.draw(text1);

        Font font2;
        Text text2;
        font2.loadFromFile("Bahnschrift.ttf");
        text2.setString(to_string(length2));
        text2.setFont(font2);
        text2.setStyle(sf::Text::Bold);
        text2.setFillColor(Color::White);
        text2.setCharacterSize(size / 1.5);
        text2.setPosition(TextX2 - 0.55 * text2.getGlobalBounds().width, TextY2 - 0.9 * text2.getGlobalBounds().height);
        window.draw(text2);
    }
};
