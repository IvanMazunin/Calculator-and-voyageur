#pragma once
#include "climits"
#include "iostream"
#include "cstdlib"
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl; 

struct Point {
	int value;
	int i;
	int j;
	friend bool operator< (Point& a, Point& b) {
		return a.i < b.i;
	}
};

class App {
	std::vector<std::vector<int>> src_paths;
	std::vector<std::vector<int>> current;
	std::vector< Point > fast;
	int amount_cities;
public:
	void run();
	void input();
	void doActions();
	void output();

void diFind(std::vector<int>& di);
void djFind(std::vector<int>& dj);
void diReducton(std::vector<int>& di);
void djReducton(std::vector<int>& dj);
void estimate(Point& mp);
void save_path(Point mp);
void reduction(Point& mp);
void print_table();
int dj_di_point(int i, int j);
};

void App::run()
{
	setlocale(LC_ALL, "ru");
	input();
	for (int i = 0; i < amount_cities; i++) {
		cout << "# Шаг" << i + 1 << endl;
			doActions();
	}
	output();
}


void App::input()
{

	cout << " Koл-во городов: ";
	cin >> amount_cities;
	src_paths.resize(amount_cities);
	for (int i = 0; i < src_paths.size(); i++)
		src_paths[i].resize(amount_cities);
	for (int i = 0; i < src_paths.size(); i++) {
		cout << char('A' + i) << ": ";
		for (int j = 0; j < src_paths.size(); j++)
			if (i != j)
				cin >> src_paths[i][j];
			else src_paths[i][j] = INT_MAX;
	}
	current = src_paths;
	fast.resize(amount_cities);

	for (int i = 0; i < fast.size(); i++)
		fast[i].value = -1;
}




void App::doActions()

{
	print_table();
	std::vector<int> di(current.size());
	std::vector<int> dj(current[0].size());
	Point mp;
	
	cout << "* Поиск мин. элементов в строке" << endl;
	diFind(di);
	cout << "* Вычитание мин. элементов в строке" << endl;;
	diReducton(di);
	print_table();
	
	cout << "* Поиск мин. элементов в столбце" << endl;;
	djFind(dj);
	cout << "* Вычитание мин. элементов в столбце" << endl;;
		djReducton(dj);
	print_table();
	
	cout << "* Оценка нулей" << endl;;
	estimate(mp);
	cout << " * Сохранение точки : (" << mp.i + 1 << " ; " << mp.j + 1 << ")" << endl;;
	save_path(mp);
	cout << "* Исключение столбца и строки для данной точки" << endl;
	reduction(mp);
	print_table();
}


void App::diFind(std::vector<int> &di)
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

void App::diReducton(std::vector<int> &di)
{
	for (int i = 0; i < current.size(); i++)
		for (int j = 0; j < current[i].size(); j++)
			if (current[i][j] != INT_MAX)
				current[i][j] -= di[i];
}

void App::djFind(std::vector<int> &dj)
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

void App::djReducton(std::vector<int> &dj)
{
	for (int i = 0; i<current.size(); i++)
		for (int j = 0; j < current[i].size(); j++)
			if (current[j][i] != INT_MAX)
				current[j][i] -= dj[i];
}

void App::estimate(Point& mp)
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
int App::dj_di_point(int i, int j)
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

void App::save_path(Point mp)
{
	for (int i = 0; i < fast.size(); i++)
		if (fast[i].value == -1) {
			fast[i] = mp;
			break;
		}
}

void App::reduction(Point &mp)
{
	int i = mp.i;
	int j = mp.j;
	for (int t = 0; t < current[0].size(); t++)
		current[t][j] = INT_MAX;
	for (int t = 0; t < current.size(); t++ )
		current[i][t] = INT_MAX;
	current[i][j] = INT_MAX;
	current[j][i] = INT_MAX;
}

void App::print_table() {
	cout << "\t";
	for (int i = 0; i<current.size(); i++)
		cout << char('A'+i) << "\t";
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

void App::output()
{
	current = src_paths;
	cout << " Исх. таблица:" << endl;
	print_table();
	
	cout << " Пути:" << endl;
	int i = 0, sum = 0;
	int tmp = 1;
	do {
		cout << tmp << " -> " << fast[i].j + 1 << endl;
		tmp = fast[i].j + 1;
		sum += src_paths[fast[i].i][fast[i].j];
		i = fast[i].j;
		
	}
	while(i != 0);
	cout << " Путь: " << sum << endl;
}
