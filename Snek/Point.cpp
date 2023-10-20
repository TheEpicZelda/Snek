#include "Point.h"

Point::Point()
{
	x_ = 0;
	y_ = 0;
}

Point::Point(int x, int y)
{
	if (x < 0)
	{
		x_ = 0;
	}
	else
	{
		x_ = x;
	}

	if (y < 0)
	{
		y_ = 0;
	}
	else
	{
		y_ = y;
	}
}

void Point::setX(int x)
{
	if (x < 0)
	{
		x_ = 0;
	}
	else
	{
		x_ = x;
	}
}

void Point::setY(int y)
{
	if (y < 0)
	{
		y_ = 0;
	}
	else
	{
		y_ = y;
	}
}

void Point::setCoords(int x, int y)
{
	if (x < 0)
	{
		x_ = 0;
	}
	else
	{
		x_ = x;
	}

	if (y < 0)
	{
		y_ = 0;
	}
	else
	{
		y_ = y;
	}
}

int Point::getX()
{
	return x_;
}

int Point::getY()
{
	return y_;
}

bool Point::operator==(const Point& p)
{
	if (x_ == p.x_ && y_ == p.y_)
	{
		return true;
	}
	return false;
}
