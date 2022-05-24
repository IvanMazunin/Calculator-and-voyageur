#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Graph.h"
#include "Drawing.h"

using namespace std;
using namespace sf;

Graph graph(6);
int cities = 6;
vector<vector<int>> mas(cities, vector<int>(cities));

void Windows() {
    sf::RenderWindow window(sf::VideoMode(900, 900), ""); 
    while (window.isOpen()) 
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear(Color(216, 164, 94));
 
        Drawing look(graph);
        look.Draw(window);

        window.display();
    }
}


void Consol() {
    char b;
    while (true) {
        
        cout << endl << "Для работы с программой выберите действие, которое хотите совершить:" << endl;
        cout << "1. Ввод новой матрицы смежности" << endl;
        cout << "2. Добавление вершины" << endl;
        cout << "3. Удаление вершины" << endl;
        cout << "4. Построение пустого графа с n вершинами" << endl;
        cout << "5. Поиск кратчайшего пути" << endl;
        cout << "6. Выход из программы" << endl << endl;
        cout << "Выполни: ";
        cin >> b;
        cout << endl;
        switch (b)
        {
        case '1': 
        {
            graph.fastWay.clear();
            cout << "Введите количество врешин: ";
            cin >> cities;
            mas.resize(cities);
            for (int i = 0; i < mas.size(); i++)
                mas[i].resize(cities);
            cout << "Введите матрицу смежности: " << endl;
            for (int i = 0; i < cities; i++)
            { 
                cout << char(65 + i) << ": ";
                for (int j = 0; j < cities; j++)
                    if (i != j)
                        cin >> mas[i][j];
                    else mas[i][j] = INT_MAX;
            }
            cout << endl;
            graph.setGraph(mas);
            break;
        }
        case '2':
        {
            graph.fastWay.clear();
            cities++;
            mas.resize(cities);
            for (int i = 0; i < mas.size(); i++)
                mas[i].resize(cities);
            cout << "Введите данные о вершине: " << endl;
            cout << char(65 + cities - 1) << ": ";
            for (int i = 0; i < cities - 1; i++)
            {
                cin >> mas[cities - 1][i];
                mas[i][cities - 1] = mas[cities - 1][i];
            }
            mas[cities - 1][cities - 1] = INT_MAX;
            cout << endl;
            graph.setGraph(mas);
            break;
        }
        case '3':
        {
            graph.fastWay.clear();
            vector<vector<int>> tmp(cities, vector<int>(cities));
            tmp = mas;
            cout << "Введите название вершины для удаления: ";
            char c;
            cin >> c;
            int i0 = int(c) - 65;
            int itmp = 0;
            for (int i = 0; i < cities; i++)
                if (i != i0)
                {
                    tmp[itmp] = mas[i];
                    itmp++;
                }
            itmp = 0;
            mas.clear();
            cities--;
            mas.resize(cities);
            for (int i = 0; i < mas.size(); i++)
                mas[i].resize(cities);

            for (int i = 0; i < cities; i++)
            {
                for (int j = 0;j <= cities;j++)
                if (j != i0)
                {
                    mas[i][itmp] = (tmp[i][j]);
                    itmp++;
                }
                itmp = 0;
            }
            graph.setGraph(mas);
            break;
        }
        case '4':
        {
            graph.fastWay.clear();
            cout << "Введите количество вершин: ";
            int n;
            cin >> n;
            cities = n;
            mas.clear();
            mas.resize(cities);
            for (int i = 0; i < mas.size(); i++)
                mas[i].resize(cities);
            graph.setGraph(mas);
            break;
        }
        case '5':graph.run(); break;
        case '6': 
            graph.fastWay.clear();
            exit(0);
            break;
        default:
            cout << endl << "Данного действия нет в списке" << endl;;
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    system("chcp1251");
    system("cls");

    cout << "РЕШЕНИЕ ЗАДАЧИ КОММИВОЯЖЕРА: " << endl;

    thread w(Windows); 
    thread c(Consol); 
    w.join(); 
    c.join(); 

    return 0;
}
