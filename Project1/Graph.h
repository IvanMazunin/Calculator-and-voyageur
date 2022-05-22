#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace sf;
const int NOVALUE = 2147483647; //îòñóòñòâèå çíà÷åíèÿ

//ìàòðèöà ñìåæíîñòè ãðàôà
class AdjacencyMatrix {
private:
	static bool isNoEmpty(std::vector<std::vector<int>> matrix);
public:
	template<class T1, class T2> struct Tuple {
		T1 item1;
		T2 item2;
	};
	std::vector<Tuple<int, int>> getWayParts() const;
	std::vector<std::vector<int>> matrix; //ìàòðèöà ñìåæíîñòè

	AdjacencyMatrix();
	AdjacencyMatrix& operator=(const AdjacencyMatrix& adjMatrix);
	int getWayLength(std::vector<Tuple<int, int>>& wayParts)const;
	AdjacencyMatrix(std::vector<std::vector<int>>& matrix);
	AdjacencyMatrix(const AdjacencyMatrix& adjMatrix);
	unsigned int getVerticesCount() const;
	std::vector<int> getWay(int startPoint) const;
};

//âåðøèíà ãðàôà
class gVertex : public Drawable {
private:
	Text text;
	CircleShape circle;

	static float VERTEX_RADIUS; //ðàäèóñ îêðóæíîñòè âåðøèí
	static int VERTEX_POINTS; //êîëè÷åñòâî òî÷åê ïðè îòðèñîâêå âåðøèí
public:
	//êîñíñòðóêòîðû, äåñòðóêòîð è îïåðàòîð ïðèñâàèâàíèÿ
	gVertex();
	gVertex(const sf::String& text, const Font& font, const int& textSize);
	gVertex& operator=(const gVertex& v);
	gVertex(const gVertex& v);
	~gVertex();

	void setPosition(float x, float y);
	static void getMoving(gVertex*& moving, std::vector<gVertex>& vertices, const Event& event, const Vector2i& cursorPos);
	static void move(gVertex*& moving, const Vector2i& cursorPos, const int& window_width, const int& window_height);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	FloatRect getGlobalBounds();
	FloatRect getLocalBounds();
	Vector2f getCenter();
	Vector2f getPosition();
	static void getPolygonSpread(std::vector<gVertex>& vertices, const Vector2f& SPREAD_CENTER, const int& SPREAD_RADIUS);
};

//ðåáðî ãðàôà
class gEdge : public Drawable {
private:
	//ãëàâíàÿ ëèíèÿ
	Vertex mainLine[2];

	//ñòðåëî÷êè ïîñåðåäèíå ãëàâíîé ëèíèè
	Vertex fromStartArrow[3];
	Vertex fromEndArrow[3];

	//òåêñò íàä ëèíèåé (äëÿ âåñîâ ðåá¸ð)
	Text fromStartText;
	Text fromEndText;



	//çíà÷åíèå âûñîòû ñòðåëî÷åê ïîñåðåäèíå ãëàâíîé ëèíèè
	static float ARROW_HEIGHT;

	//ïîëó÷åíèå äëèíû âåêòîðà
	static float getLength(const Vector2f& vec);
	//ïîëó÷åíèå åäèíè÷íîãî âåêòîðà
	static Vector2f getUnitVector(const Vector2f& vec);
	//ïîëó÷åíèå êîîðäèíàò âåêòîðà íà îñíîâå òî÷åê íà÷àëà è êîíöà
	static Vector2f getVector(const Vector2f& startPoint, const Vector2f& endPoint);
	//ïîëó÷åíèå êîîðäèíàò êîíöà âûñîòû òðåóãîëüíèêà îáðàçóþùåãî ïåðâóþ ñòðåëî÷êó
	Vector2f getArrowHeightPoint1();
	//ïîëó÷åíèå êîîðäèíàò êîíöà âûñîòû òðåóãîëüíèêà îáðàçóþùåãî âòîðóþ ñòðåëî÷êó
	Vector2f getArrowHeightPoint2();
	//öåíòð ïåðâîé ïîëîâèíû îò ñòàðòà (òàì áóäåò ðàçìåùàòüñÿ òåêñò)
	Vector2f getStartHalfCenter();
	//öåíòð âòîðîé ïîëîâèíû îò ñòàðòà (òàì áóäåò ðàçìåùàòüñÿ òåêñò)
	Vector2f getEndHalfCenter();
	static Vector2f getCenter(const Vector2f& startPoint, const Vector2f& endPoint);

public:
	//çíà÷åíèå âåñà ðåáðà
	int fromStartLength = NOVALUE;
	int fromEndLength = NOVALUE;
	void setFromStartArrowColor(const Color& c);
	void setFromEndArrowColor(const Color& c);

	gEdge(const int& fromStartLength, const int& fromEndLength, const Font& font, const int& textSize);
	Vector2f getStart();
	Vector2f getEnd();
	void setPosition(const Vector2f& startPoint, const Vector2f& endPoint);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

class Graph {
public:
	AdjacencyMatrix adjMatrix;
	std::vector<gEdge> edges;
	std::vector<gVertex> vertices;
	Graph(std::vector<std::vector<int>>& matrix, const std::vector<std::wstring>& names,
		const Font& font, const int& textSize, const Vector2f& SPREAD_CENTER, const int& SPREAD_RADIUS);
	void loadNewData(std::vector<std::vector<int>>& matrix, const std::vector<std::wstring>& names,
		const Font& font, const int& textSize, const Vector2f& SPREAD_CENTER, const int& SPREAD_RADIUS);
	void snapEdgesToVertices();
	void showHamiltoneCycle();
};