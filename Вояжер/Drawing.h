#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include "Graph.h"
#include "Node.h"
#include "OneWay.h"
#include "TwoWays.h"

using namespace std;
using namespace sf;

class Drawing {
private:
    vector<Node> Nodes; 
    Graph graph; 
    int size; 
    vector<vector<int>> save_paths;
public:

    Drawing(Graph graph) {
        this->graph = graph; 
        this->size = graph.GetSize(); 
        save_paths = graph.GetGraph();
        Nodes = vector<Node>(size, Node()); 
        for (int i = 0; i < size; i++) 
            Nodes[i] = Node(65 + i, 40, 450 - 350 * sin(-2 * PI * i / size), 450 - 350 * cos(-2 * PI * i / size));
    }

    void DrawGraph(sf::RenderWindow& window) {
        if (graph.fastWay.empty())
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) { 
                if (save_paths[i][j] != INT_MAX && save_paths[j][i] != INT_MAX)
                { 
                    Way* c;
                    c = new TwoWays(Nodes[i], Nodes[j], save_paths[i][j], save_paths[j][i], Color::Black);
                    c->Draw(window); 
                    delete c;
                }
            }
        }
        for (list<char>::iterator i = graph.fastWay.begin(); i != graph.fastWay.end();) {
            int a = int(*i) - 65;
            int b = 0;
            i++;
            if (i != graph.fastWay.end())
                b = int(*i) - 65;
            else
                b = int(*graph.fastWay.begin()) - 65;
            
            if (save_paths[a][b] != INT_MAX)
            { 
                Way* c;
                c = new OneWay(Nodes[a], Nodes[b], save_paths[a][b], Color(70, 130, 180));
                c->Draw(window);
                delete c;
            }
        }
        for (int i = 0; i < size; i++) {
            Nodes[i].Draw(window);
        }
    }
    void Draw(sf::RenderWindow& window) {
        DrawGraph(window);
    }
};