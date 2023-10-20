#pragma once
#include "Point.h"
#include <vector>

class Snake
{
public:
	Snake();
	int getX(int segment);
	int getY(int segment);
	void getCoords(int segment, int& x, int& y);
	Point getSegment(int segment);
	Point getHead();
	Point getTail();
	Point getSecondLast();
	char getDirection();
	int getLength();
	void move(char direction);
	void reset();
	void grow();
	bool hitSelf();
	bool hitWall(int xcoord, int ycoord);

private:
	void setCoords(int segment, int x, int y);
	void setCoords(int segment, Point coords);
	

	std::vector<Point> segments_;
	int length_;
	char direction_;
};

