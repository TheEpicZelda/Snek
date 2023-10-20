#pragma once
#include "framework.h"
#include "Point.h"

bool isBelowCurrent(Point current, Point other);
bool isAboveCurrent(Point current, Point other);
bool isLeftOfCurrent(Point current, Point other);
bool isRightOfCurrent(Point current, Point other);

void drawSnakeHead(HDC hdc, char direction, Point head, int xOffset, int yOffset);
void drawSnakeTail(HDC hdc, Point tail, Point previous, Point previous2, int xOffset, int yOffset);
void drawSnakeBodySegment(HDC hdc, Point current, Point previous, Point next, int xOffset, int yOffset);

