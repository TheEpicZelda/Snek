#include "DrawSnake.h"

void drawLine(HDC hdc, int startX, int startY, int endX, int endY, int r, int g, int b, int xOffset, int yOffset)
{

    if (startX == endX)
    {
        for (int i = startY; i < endY; i++)
        {
            SetPixel(hdc, startX, i, RGB(r, g, b));
        }
    }
    else if (startY == endY)
    {
        for (int i = startX; i < endX; i++)
        {
            SetPixel(hdc, i, startY, RGB(r, g, b));
        }
    }
    else
    {
    }
}

bool isBelowCurrent(Point current, Point other)
{
    if ((current.getX() == other.getX()) && (current.getY() < other.getY()))
    {
        return true;
    }
    return false;
}

bool isAboveCurrent(Point current, Point other)
{
    if ((current.getX() == other.getX()) && (current.getY() > other.getY()))
    {
        return true;
    }
    return false;
}

bool isLeftOfCurrent(Point current, Point other)
{
    if ((current.getX() > other.getX()) && (current.getY() == other.getY()))
    {
        return true;
    }
    return false;
}

bool isRightOfCurrent(Point current, Point other)
{
    if ((current.getX() < other.getX()) && (current.getY() == other.getY()))
    {
        return true;
    }
    return false;
}



void drawSnakeHead(HDC hdc, char direction, Point head , int xOffset, int yOffset)
{
    if (direction == 'r')
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, head.getX() * 10 + xOffset, head.getY() * 10 + yOffset, (head.getX() + 1) * 10 + xOffset, (head.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, head.getX() * 10 + xOffset, head.getY() * 10 + yOffset + 1, (head.getX() + 1) * 10 + xOffset - 1, (head.getY() + 1) * 10 + yOffset - 1);

        SetPixel(hdc, head.getX() * 10 + xOffset + 6, head.getY() * 10 + yOffset + 3, RGB(0, 0, 0));
        SetPixel(hdc, head.getX() * 10 + xOffset + 6, head.getY() * 10 + yOffset + 6, RGB(0, 0, 0));
        /*
        //Right line
        drawLine(hdc, (head.getX() + 1) * 10 + xOffset, head.getY() * 10 + yOffset + 4, (head.getX() + 1) * 10 + xOffset, (head.getY() + 1) * 10 + yOffset - 2, 0, 0, 0, xOffset, yOffset);

        int xBase = head.getX() * 10 + xOffset;
        int yBase = head.getY() * 10 + yOffset + 5;
        int yChange = 2;

        //Top and bottom as well as rounded corners
        for (int i = xBase + 10; i >= xBase; i--)
        {
            SetPixel(hdc, i, yBase + yChange, RGB(0, 0, 0));
            SetPixel(hdc, i, yBase - yChange, RGB(0, 0, 0));

            if (i != xBase + 10)
            {
                for (int j = yBase - yChange + 1; j < yBase + yChange; j++)
                {
                    SetPixel(hdc, i, j, RGB(0, 220, 0));
                }
            }

            if (yChange < 5)
            {
                yChange++;
            }
        }*/
    }
    else if (direction == 'l')
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, head.getX() * 10 + xOffset, head.getY() * 10 + yOffset, (head.getX() + 1) * 10 + xOffset, (head.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, head.getX() * 10 + xOffset + 1, head.getY() * 10 + yOffset + 1, (head.getX() + 1) * 10 + xOffset, (head.getY() + 1) * 10 + yOffset - 1);

        SetPixel(hdc, head.getX() * 10 + xOffset + 3, head.getY() * 10 + yOffset + 3, RGB(0, 0, 0));
        SetPixel(hdc, head.getX() * 10 + xOffset + 3, head.getY() * 10 + yOffset + 6, RGB(0, 0, 0));

        /*
        //Left line
        drawLine(hdc, (head.getX()) * 10 + xOffset, head.getY() * 10 + yOffset + 4, (head.getX()) * 10 + xOffset, (head.getY() + 1) * 10 + yOffset - 2, 0, 0, 0, xOffset, yOffset);

        int xBase = head.getX() * 10 + xOffset;
        int yBase = head.getY() * 10 + yOffset + 5;
        int yChange = 2;

        for (int i = xBase; i < xBase + 10; i++)
        {
            SetPixel(hdc, i, yBase + yChange, RGB(0, 0, 0));
            SetPixel(hdc, i, yBase - yChange, RGB(0, 0, 0));

            if (i != xBase)
            {
                for (int j = yBase - yChange + 1; j < yBase + yChange; j++)
                {
                    SetPixel(hdc, i, j, RGB(0, 220, 0));
                }
            }

            if (yChange < 5)
            {
                yChange++;
            }
        }*/
    }
    else if (direction == 'u')
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, head.getX() * 10 + xOffset, head.getY() * 10 + yOffset, (head.getX() + 1) * 10 + xOffset, (head.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, head.getX() * 10 + xOffset + 1, head.getY() * 10 + yOffset + 1, (head.getX() + 1) * 10 + xOffset - 1, (head.getY() + 1) * 10 + yOffset);

        SetPixel(hdc, head.getX() * 10 + xOffset + 3, head.getY() * 10 + yOffset + 3, RGB(0, 0, 0));
        SetPixel(hdc, head.getX() * 10 + xOffset + 6, head.getY() * 10 + yOffset + 3, RGB(0, 0, 0));

        /*
        //Top line
        drawLine(hdc, head.getX() * 10 + xOffset + 4, head.getY() * 10 + yOffset, (head.getX() + 1) * 10 + xOffset - 2, head.getY() * 10 + yOffset, 0, 0, 0, xOffset, yOffset);

        int xBase = head.getX() * 10 + xOffset + 5;
        int yBase = head.getY() * 10 + yOffset;
        int xChange = 2;

        for (int i = yBase; i < yBase + 10; i++)
        {
            SetPixel(hdc, xBase + xChange, i, RGB(0, 0, 0));
            SetPixel(hdc, xBase - xChange, i, RGB(0, 0, 0));

            if (i != yBase)
            {
                for (int j = xBase - xChange + 1; j < xBase + xChange; j++)
                {
                    SetPixel(hdc, j, i, RGB(0, 220, 0));
                }
            }

            if (xChange < 5)
            {
                xChange++;
            }
        }*/
    }
    else if (direction == 'd')
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, head.getX() * 10 + xOffset, head.getY() * 10 + yOffset , (head.getX() + 1) * 10 + xOffset, (head.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, head.getX() * 10 + xOffset + 1, head.getY() * 10 + yOffset, (head.getX() + 1) * 10 + xOffset - 1, (head.getY() + 1) * 10 + yOffset - 1);

        SetPixel(hdc, head.getX() * 10 + xOffset + 3, head.getY() * 10 + yOffset + 6, RGB(0, 0, 0));
        SetPixel(hdc, head.getX() * 10 + xOffset + 6, head.getY() * 10 + yOffset + 6, RGB(0, 0, 0));

        /*
        //Bottom line
        drawLine(hdc, head.getX() * 10 + xOffset + 4, (head.getY() + 1) * 10 + yOffset, (head.getX() + 1) * 10 + xOffset - 2, (head.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);

        int xBase = head.getX() * 10 + xOffset + 5;
        int yBase = head.getY() * 10 + yOffset;
        int xChange = 2;

        for (int i = yBase + 10; i >= yBase; i--)
        {
            SetPixel(hdc, xBase + xChange, i, RGB(0, 0, 0));
            SetPixel(hdc, xBase - xChange, i, RGB(0, 0, 0));

            if (i != yBase + 10)
            {
                for (int j = xBase - xChange + 1; j < xBase + xChange; j++)
                {
                    SetPixel(hdc, j, i, RGB(0, 220, 0));
                }
            }

            if (xChange < 5)
            {
                xChange++;
            }
        }*/
    }
}

void drawSnakeTail(HDC hdc, Point tail, Point previous, Point previous2, int xOffset, int yOffset)
{
    if (tail.getX() == previous.getX())
    {
        if (tail.getY() > previous.getY()) //Tail tip pointing down
        {
            SetDCBrushColor(hdc, RGB(0, 255, 0));
            SetDCPenColor(hdc, RGB(0, 0, 0));
            Rectangle(hdc, tail.getX() * 10 + xOffset, tail.getY() * 10 + yOffset, (tail.getX() + 1) * 10 + xOffset, (tail.getY() + 1) * 10 + yOffset);

            SetDCPenColor(hdc, RGB(0, 255, 0));
            Rectangle(hdc, tail.getX() * 10 + xOffset + 1, tail.getY() * 10 + yOffset, (tail.getX() + 1) * 10 + xOffset - 1, (tail.getY() + 1) * 10 + yOffset - 1);

            /*int xBase = tail.getX() * 10 + xOffset + 5;
            int yBase = tail.getY() * 10 + yOffset + 10;
            int xChange = 1;
            SetPixel(hdc, xBase, yBase, RGB(0, 0, 0));
            for (int i = yBase - 1; i >= yBase - 10; i--)
            {
                SetPixel(hdc, xBase + xChange, i, RGB(0, 0, 0));
                SetPixel(hdc, xBase - xChange, i, RGB(0, 0, 0));

                if (i != yBase)
                {
                    for (int j = xBase - xChange + 1; j < xBase + xChange; j++)
                    {
                        SetPixel(hdc, j, i, RGB(0, 220, 0));
                    }
                }

                if (!(i % 2))
                {
                    xChange++;
                }
            }*/
        }
        else if (tail.getY() < previous.getY()) //Tail tip pointing up
        {
            SetDCBrushColor(hdc, RGB(0, 255, 0));
            SetDCPenColor(hdc, RGB(0, 0, 0));
            Rectangle(hdc, tail.getX() * 10 + xOffset, tail.getY() * 10 + yOffset, (tail.getX() + 1) * 10 + xOffset, (tail.getY() + 1) * 10 + yOffset);

            SetDCPenColor(hdc, RGB(0, 255, 0));
            Rectangle(hdc, tail.getX() * 10 + xOffset + 1, tail.getY() * 10 + yOffset + 1, (tail.getX() + 1) * 10 + xOffset - 1, (tail.getY() + 1) * 10 + yOffset);

            /*int xBase = tail.getX() * 10 + xOffset + 5;
            int yBase = tail.getY() * 10 + yOffset;
            int xChange = 1;
            SetPixel(hdc, xBase, yBase, RGB(0, 0, 0));
            for (int i = yBase + 1; i < yBase + 10; i++)
            {
                SetPixel(hdc, xBase + xChange, i, RGB(0, 0, 0));
                SetPixel(hdc, xBase - xChange, i, RGB(0, 0, 0));

                if (i != yBase + 10)
                {
                    for (int j = xBase - xChange + 1; j < xBase + xChange; j++)
                    {
                        SetPixel(hdc, j, i, RGB(0, 220, 0));
                    }
                }

                if (i % 2)
                {
                    xChange++;
                }
            }*/
        }
        else 
        {
            //Food just eaten
            drawSnakeTail(hdc, tail, previous2, previous2, xOffset, yOffset);
        }
    }
    else if (tail.getY() == previous.getY())
    {
        if (tail.getX() > previous.getX()) //Tail tip pointing right
        {
            SetDCBrushColor(hdc, RGB(0, 255, 0));
            SetDCPenColor(hdc, RGB(0, 0, 0));
            Rectangle(hdc, tail.getX() * 10 + xOffset, tail.getY() * 10 + yOffset, (tail.getX() + 1) * 10 + xOffset, (tail.getY() + 1) * 10 + yOffset);

            SetDCPenColor(hdc, RGB(0, 255, 0));
            Rectangle(hdc, tail.getX() * 10 + xOffset, tail.getY() * 10 + yOffset + 1, (tail.getX() + 1) * 10 + xOffset - 1, (tail.getY() + 1) * 10 + yOffset - 1);

            /*
            //Right line
            drawLine(hdc, (tail.getX() + 1) * 10 + xOffset, tail.getY() * 10 + yOffset + 4, (tail.getX() + 1) * 10 + xOffset, (tail.getY() + 1) * 10 + yOffset - 2, 0, 0, 0, xOffset, yOffset);

            int xBase = tail.getX() * 10 + xOffset;
            int yBase = tail.getY() * 10 + yOffset + 5;
            int yChange = 2;

            //Top and bottom as well as rounded corners
            for (int i = xBase + 10; i >= xBase; i--)
            {
                SetPixel(hdc, i, yBase + yChange, RGB(0, 0, 0));
                SetPixel(hdc, i, yBase - yChange, RGB(0, 0, 0));

                if (i != xBase + 10)
                {
                    for (int j = yBase - yChange + 1; j < yBase + yChange; j++)
                    {
                        SetPixel(hdc, i, j, RGB(0, 220, 0));
                    }
                }

                if (yChange < 5)
                {
                    yChange++;
                }
            }*/

            /*int xBase = tail.getX() * 10 + xOffset + 10;
            int yBase = tail.getY() * 10 + yOffset + 5;
            int yChange = 1;
            SetPixel(hdc, xBase, yBase, RGB(0, 0, 0));
            for (int i = xBase - 1; i >= xBase - 10; i--)
            {
                SetPixel(hdc, i, yBase + yChange, RGB(0, 0, 0));
                SetPixel(hdc, i, yBase - yChange, RGB(0, 0, 0));

                if (i != xBase)
                {
                    for (int j = yBase - yChange + 1; j < yBase + yChange; j++)
                    {
                        SetPixel(hdc, i, j, RGB(0, 220, 0));
                    }
                }

                if (!(i % 2))
                {
                    yChange++;
                }
            }*/
        }
        else if (tail.getX() < previous.getX()) //Tail tip pointing left
        {
            SetDCBrushColor(hdc, RGB(0, 255, 0));
            SetDCPenColor(hdc, RGB(0, 0, 0));
            Rectangle(hdc, tail.getX() * 10 + xOffset, tail.getY() * 10 + yOffset, (tail.getX() + 1) * 10 + xOffset, (tail.getY() + 1) * 10 + yOffset);

            SetDCPenColor(hdc, RGB(0, 255, 0));
            Rectangle(hdc, tail.getX() * 10 + xOffset + 1, tail.getY() * 10 + yOffset + 1, (tail.getX() + 1) * 10 + xOffset, (tail.getY() + 1) * 10 + yOffset - 1);

            /*
            int xBase = tail.getX() * 10 + xOffset;
            int yBase = tail.getY() * 10 + yOffset + 5;
            int yChange = 1;
            SetPixel(hdc, xBase,yBase,RGB(0,0,0));
            for (int i = xBase + 1; i < xBase + 10; i++)
            {
                SetPixel(hdc, i, yBase+yChange, RGB(0,0,0));
                SetPixel(hdc, i, yBase-yChange, RGB(0,0,0));

                if (i != xBase + 10)
                {
                    for (int j = yBase - yChange + 1; j < yBase + yChange; j++)
                    {
                        SetPixel(hdc, i, j, RGB(0, 220, 0));
                    }
                }

                if (i % 2)
                {
                    yChange++;
                }
            }*/
        }
    }
}

void drawSnakeBodySegment(HDC hdc, Point current, Point previous, Point next, int xOffset, int yOffset)
{
    if ((isAboveCurrent(current, previous) || isAboveCurrent(current, next)) && (isBelowCurrent(current, previous) || isBelowCurrent(current, next))) //Previous and next are above and below current
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset + 1, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset - 1, (current.getY() + 1) * 10 + yOffset);

        /*
        //Left line
        drawLine(hdc, (current.getX()) * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX()) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);
        //Right line
        drawLine(hdc, (current.getX() + 1) * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);

        //Coloring the segment
        for (int i = current.getX() * 10 + xOffset + 1; i < (current.getX() + 1) * 10 + xOffset; i++)
        {
            drawLine(hdc, i, current.getY() * 10 + yOffset, i, (current.getY() + 1) * 10 + yOffset, 0, 220, 0, xOffset, yOffset);
        }*/
    }
    else if ((isLeftOfCurrent(current, previous) || isLeftOfCurrent(current, next)) && (isRightOfCurrent(current, previous) || isRightOfCurrent(current, next))) //Previous and next are left/right of current
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset + 1, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset - 1);

        /*
        //Top line
        drawLine(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, current.getY() * 10 + yOffset, 0, 0, 0, xOffset, yOffset);
        //Bottom line
        drawLine(hdc, current.getX() * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);

        //Coloring the segment
        for (int i = current.getY() * 10 + yOffset + 1; i < (current.getY() + 1) * 10 + yOffset; i++)
        {
            drawLine(hdc, current.getX() * 10 + xOffset, i, (current.getX() + 1) * 10 + xOffset, i, 0, 220, 0, xOffset, yOffset);
        }*/
    }
    else if ((isLeftOfCurrent(current, previous) || isLeftOfCurrent(current, next)) && (isAboveCurrent(current, previous) || isAboveCurrent(current, next))) //Left/above
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset - 1, (current.getY() + 1) * 10 + yOffset - 1);

        SetPixel(hdc, current.getX() * 10 + xOffset, (current.getY()) * 10 + yOffset, RGB(0, 0, 0));

        /*
        //Right line
        drawLine(hdc, (current.getX() + 1) * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);
        //Bottom line
        drawLine(hdc, current.getX() * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);

        for (int i = current.getY() * 10 + yOffset; i < (current.getY() + 1) * 10 + yOffset; i++)
        {
            drawLine(hdc, current.getX() * 10 + xOffset, i, (current.getX() + 1) * 10 + xOffset, i, 0, 220, 0, xOffset, yOffset);
        }*/
    }
    else if ((isLeftOfCurrent(current, previous) || isLeftOfCurrent(current, next)) && (isBelowCurrent(current, previous) || isBelowCurrent(current, next))) //Left/below
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset + 1, (current.getX() + 1) * 10 + xOffset - 1, (current.getY() + 1) * 10 + yOffset);

        SetPixel(hdc, current.getX() * 10 + xOffset, (current.getY() + 1) * 10 + yOffset - 1, RGB(0, 0, 0));

        /*
        //Top line
        drawLine(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, current.getY() * 10 + yOffset, 0, 0, 0, xOffset, yOffset);
        //Right line
        drawLine(hdc, (current.getX() + 1) * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);

        for (int i = current.getY() * 10 + yOffset + 1; i < (current.getY() + 1) * 10 + yOffset; i++)
        {
            drawLine(hdc, current.getX() * 10 + xOffset, i, (current.getX() + 1) * 10 + xOffset, i, 0, 220, 0, xOffset, yOffset);
        }*/
    }
    else if ((isRightOfCurrent(current, previous) || isRightOfCurrent(current, next)) && (isAboveCurrent(current, previous) || isAboveCurrent(current, next))) //Right/above
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset + 1, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset - 1);

        SetPixel(hdc, (current.getX() + 1) * 10 + xOffset - 1, current.getY() * 10 + yOffset, RGB(0, 0, 0));

        /*
        //Bottom line
        drawLine(hdc, current.getX() * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);
        //Left line
        drawLine(hdc, (current.getX()) * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX()) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);

        for (int i = current.getY() * 10 + yOffset; i < (current.getY() + 1) * 10 + yOffset; i++)
        {
            drawLine(hdc, current.getX() * 10 + xOffset + 1, i, (current.getX() + 1) * 10 + xOffset, i, 0, 220, 0, xOffset, yOffset);
        }*/
    }
    else if ((isRightOfCurrent(current, previous) || isRightOfCurrent(current, next)) && (isBelowCurrent(current, previous) || isBelowCurrent(current, next))) //Right/below
    {
        SetDCBrushColor(hdc, RGB(0, 255, 0));
        SetDCPenColor(hdc, RGB(0, 0, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset);

        SetDCPenColor(hdc, RGB(0, 255, 0));
        Rectangle(hdc, current.getX() * 10 + xOffset + 1, current.getY() * 10 + yOffset + 1, (current.getX() + 1) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset);

        SetPixel(hdc, (current.getX() + 1) * 10 + xOffset - 1, (current.getY() + 1) * 10 + yOffset - 1, RGB(0, 0, 0));

        /*
        //Top line
        drawLine(hdc, current.getX() * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX() + 1) * 10 + xOffset, current.getY() * 10 + yOffset, 0, 0, 0, xOffset, yOffset);
        //Left line
        drawLine(hdc, (current.getX()) * 10 + xOffset, current.getY() * 10 + yOffset, (current.getX()) * 10 + xOffset, (current.getY() + 1) * 10 + yOffset, 0, 0, 0, xOffset, yOffset);

        for (int i = current.getY() * 10 + yOffset + 1; i < (current.getY() + 1) * 10 + yOffset; i++)
        {
            drawLine(hdc, current.getX() * 10 + xOffset + 1, i, (current.getX() + 1) * 10 + xOffset, i, 0, 220, 0, xOffset, yOffset);
        }*/
    }
}


