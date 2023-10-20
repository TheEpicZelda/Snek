#include "Snake.h"

Snake::Snake()
{
	segments_.push_back(Point(10, 2));
	segments_.push_back(Point(9, 2));
	segments_.push_back(Point(8, 2));
	segments_.push_back(Point(7, 2));
	segments_.push_back(Point(6, 2));
	length_ = 5;
	direction_ = 'r';
}

int Snake::getX(int segment)
{
	return segments_[segment].getX();
}

int Snake::getY(int segment)
{
	return segments_[segment].getY();
}

void Snake::getCoords(int segment, int& x, int& y)
{
	x = segments_[segment].getX();
	y = segments_[segment].getY();
}

Point Snake::getSegment(int segment)
{
	return segments_[segment];
}

Point Snake::getHead()
{
    return segments_[0];
}

Point Snake::getTail()
{
    return segments_[length_-1];
}

Point Snake::getSecondLast()
{
    return segments_[length_-2];
}

char Snake::getDirection()
{
	return direction_;
}

int Snake::getLength()
{
	return length_;
}

void Snake::move(char direction)
{
    if (direction == 'u') //User presses up
    {
        if (direction_ != 'd')
        {
            //update coordinates: y - 1
            for (int i = (length_ - 1); i > 0; i--)
            {
                setCoords(i, segments_[i - 1]);
            }
            segments_[0].setY(segments_[0].getY() - 1);

            direction_ = 'u';
        }
    }
    else if (direction == 'd') //User presses down
    {
        if (direction_ != 'u')
        {
            //update coordinates: y + 1
            for (int i = length_ - 1; i > 0; i--)
            {
                setCoords(i, segments_[i - 1]);
            }
            segments_[0].setY(segments_[0].getY() + 1);

            direction_ = 'd';
        }
    }
    else if (direction == 'l') //User presses left
    {
        if (direction_ != 'r')
        {
            //update coordinates: x - 1
            for (int i = length_ - 1; i > 0; i--)
            {
                setCoords(i, segments_[i - 1]);
            }
            segments_[0].setX(segments_[0].getX() - 1);

            direction_ = 'l';
        }
    }
    else if (direction == 'r') //User presses right
    {
        if (direction_ != 'l')
        {
            //update coordinates: x + 1 
            for (int i = length_ - 1; i > 0; i--)
            {
                setCoords(i, segments_[i - 1]);
            }
            segments_[0].setX(segments_[0].getX() + 1);

            direction_ = 'r';
        }
    }
}

void Snake::reset()
{
    segments_.clear();
	segments_.push_back(Point(10, 2));
	segments_.push_back(Point(9, 2));
	segments_.push_back(Point(8, 2));
	segments_.push_back(Point(7, 2));
	segments_.push_back(Point(6, 2));
	length_ = 5;
	direction_ = 'r';
}

void Snake::grow()
{
    //segments_[0].setCoords(1, 1);
    segments_.push_back(segments_[length_-1]);
    length_ = length_ + 1;
}

bool Snake::hitSelf()
{
    for (int i = 4; i < length_; i++)
    {
        if (segments_[0] == segments_[i])
        {
            return true;
        }
    }

    return false;
}

bool Snake::hitWall(int xcoord, int ycoord)
{
    if (((segments_[0].getX() == 0) && (direction_ == 'l')) || ((segments_[0].getX() > (xcoord)) && (direction_ == 'r')) ||
        ((segments_[0].getY() == 0) && (direction_ == 'u')) || ((segments_[0].getY() > (ycoord)) && (direction_ == 'd')))
    {
        return true;
    }
    return false;
}

void Snake::setCoords(int segment, int x, int y)
{
	segments_[segment].setCoords(x, y);
}

void Snake::setCoords(int segment, Point coords)
{
    segments_[segment].setCoords(coords.getX(), coords.getY());
}


