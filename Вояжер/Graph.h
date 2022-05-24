#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <list>
#include <string>
#include <cmath>

using namespace std;
using namespace sf;

struct Point {
    int value;
    int i;
    int j;
    friend bool operator< (Point& a, Point& b) {
        return a.i < b.i;
    }
};

class Graph {
    std::vector<std::vector<int>> save_paths;
    std::vector<std::vector<int>> current;
    std::vector< Point > fast;
    int size;
public:
    list<char> fastWay;
    void run();
    void input();
    void computing();
    void output();

    void find_di(std::vector<int>& di);
    void red_di(std::vector<int>& di);
    void find_dj(std::vector<int>& dj);
    void red_dj(std::vector<int>& dj);
    void estimate(Point& mp);
    void save_path(Point mp);
    void reduction(Point& mp);
    void print_table();
    int dj_di_point(int i, int j);

    
    Graph() {}

    Graph(int size) {
        this->size = size;
        this->save_paths = vector<vector<int>>(size, vector<int>(size));

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                this->save_paths[i][j] = 0;
        for (int i = 0; i < size; i++) 
            this->save_paths[i][i] = INT_MAX;
    }

    void setGraph(vector<vector<int>> mas) {
        this->size = mas.size();
        this->save_paths = vector<vector<int>>(size, vector<int>(size));

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                this->save_paths[i][j] = mas[i][j];
        for (int i = 0; i < size; i++)
            mas[i][i] = INT_MAX;
    }

    Graph(const Graph& graph) {
        this->size = graph.size;
        this->save_paths = vector<vector<int>>(size, vector<int>(size));
        this->fastWay = graph.fastWay;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                this->save_paths[i][j] = graph.save_paths[i][j];
    }
 
    vector<vector<int>> GetGraph() {
        return save_paths;
    }

    int GetSize() {
        return size;
    }
    list<char> GetFast() {
        return fastWay;
    }
};

void Graph::run()
{
    setlocale(LC_ALL, "ru");
    input();
    for (int i = 0; i < size; i++) {
        cout <<  "# Шаг" << i + 1 << ":" << endl;
        computing();
    }
    output();
}


void Graph::input()
{

    current = save_paths;
    fast.resize(size);

    for (int i = 0; i < fast.size(); i++)
        fast[i].value = -1;
}

void Graph::computing()

{
    print_table();
    std::vector<int> di(current.size());
    std::vector<int> dj(current[0].size());
    Point mp;

    cout << "* Поиск мин. элементов в строке" << endl;
    find_di(di);
    cout << "* Вычитание мин. элементов в строке" << endl;
    red_di(di);
    print_table();

    cout << "* Поиск мин. элементов в столбце" << endl;
    find_dj(dj);
    cout << "* Âû÷èòàíèå ìèí. ýëåìåíòîâ â ñòîëáöå" << endl;
    red_dj(dj);
    print_table();

    cout << "* Îöåíêà íóëåé\n";
    estimate(mp);
    cout << " * Ñîõðàíåíèå ïóòè : (" << mp.i + 1 << "->" << mp.j + 1 << ")" << endl;
    save_path(mp);
    cout << "* Èñêëþ÷åíèå ñòðîêè è ñòîëáöà" << endl;
    reduction(mp);
    print_table();
}

void Graph::find_di(std::vector<int>& di)
{
    int min;
    for (int i = 0; i < current.size(); i++) {
        min = INT_MAX;
        for (int j = 0; j < current[i].size(); j++)
            if (current[i][j] != INT_MAX)
                if (current[i][j] < min)
                    min = current[i][j];
        if (min != INT_MAX)
            di[i] = min;
        else
            di[i] = 0;
    }
    for (int i = 0; i < di.size(); i++)
        cout << "di: " << di[i] << " ";
    cout << endl;
}

void Graph::red_di(std::vector<int>& di)
{
    for (int i = 0; i < current.size(); i++)
        for (int j = 0; j < current[i].size(); j++)
            if (current[i][j] != INT_MAX)
                current[i][j] -= di[i];
}

void Graph::find_dj(std::vector<int>& dj)
{
    int min;
    for (int i = 0; i < current.size(); i++) {
        min = INT_MAX;
        for (int j = 0; j < current[i].size(); j++)
            if (current[j][i] != INT_MAX)
                if (current[j][i] < min)
                    min = current[j][i];
        if (min != INT_MAX)
            dj[i] = min;
        else
            dj[i] = 0;
    }
    for (int i = 0; i < dj.size(); i++)
        cout << "dj: " << dj[i] << " ";
    cout << endl;
}

void Graph::red_dj(std::vector<int>& dj)
{
    for (int i = 0; i < current.size(); i++)
        for (int j = 0; j < current[i].size(); j++)
            if (current[j][i] != INT_MAX)
                current[j][i] -= dj[i];
}

void Graph::estimate(Point& mp)
{
    int dist = 0;
    mp.value = INT_MIN;
    for (int i = 0; i < current.size(); i++)
        for (int j = 0; j < current[i].size(); j++)
            if (current[i][j] != INT_MAX && current[i][j] == 0) {
                dist = dj_di_point(i, j);
                if (dist > mp.value) {
                    mp.value = dist;
                    mp.i = i;
                    mp.j = j;
                }
            }
}
int Graph::dj_di_point(int i, int j)
{
    int di = INT_MAX, dj = INT_MAX;
    for (int t = 0; t < current[0].size(); t++)
        if (t != i && current[t][j] != INT_MAX)
            if (current[t][j] < dj)
                dj = current[t][j];
    for (int t = 0; t < current.size(); t++)
        if (t != j && current[i][t] != INT_MAX)
            if (current[i][t] < di)
                di = current[i][t];

    return di + dj;
}

void Graph::save_path(Point mp)
{
    for (int i = 0; i < fast.size(); i++)
        if (fast[i].value == -1) {
            fast[i] = mp;
            break;
        }
}

void Graph::reduction(Point& mp)
{
    int i = mp.i;
    int j = mp.j;
    for (int t = 0; t < current[0].size(); t++)
        if (current[t][j] != INT_MAX)
            current[t][j] = INT_MAX;
    for (int t = 0; t < current.size(); t++)
        if (current[i][t] != INT_MAX)
            current[i][t] = INT_MAX;
    current[i][j] = INT_MAX;
    current[j][i] = INT_MAX;
}

void Graph::print_table() {
    cout << "\t";
    for (int i = 0; i < current.size(); i++)
        cout << char('A' + i) << "\t";
    cout << endl;

    for (int i = 0; i < current.size(); i++) {
        cout << char('A' + i) << "\t";
        for (int j = 0; j < current[i].size(); j++)
            if (current[i][j] == INT_MAX)
                cout << "M\t";
            else
                cout << current[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void Graph::output()
{
    current = save_paths;
    cout << " Èñõîäíàÿ òàáëèöà:" << endl;
    print_table();
    std::sort(fast.begin(), fast.end());
    cout << " Ïóòè:" << endl;
    int i = 0, sum = 0;
    int tmp = 0;
    fastWay.push_back(char('A' + tmp));
    do {
        cout << char('A' + tmp) << " -> " << char('A' + fast[i].j) << endl;
        tmp = fast[i].j;
        fastWay.push_back(char('A' + tmp));
        sum += save_paths[fast[i].i][fast[i].j];
        i = fast[i].j;

    } while (i != 0);
    cout << " Ïóòü: " << sum << endl;
    for (list<char>::iterator i = fastWay.begin(); i != fastWay.end(); i++) {
        cout << (*i) << " ";
    }
}

