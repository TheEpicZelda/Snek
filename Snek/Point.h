#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	void setX(int x);
	void setY(int y);
	void setCoords(int x, int y);
	int getX();
	int getY();
	bool operator == (const Point& p);

private:
	int x_;
	int y_;
};

