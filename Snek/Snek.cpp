// Snek.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Snek.h"
#include "Snake.h"
#include "DrawSnake.h"
#include <time.h>
#include <string>
#include <iostream>

#define MAX_LOADSTRING 100

#ifdef UNICODE
typedef std::wostringstream tstringstream;
#else
typedef std::ostringstream tstringstream;
#endif

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
char inputDirection;
char currentDirection = 'r';
int snekLength;
Point snekments[3200];
Point food;
Point testTail[100];
int score = 0;
int xCoords = 80;
int yCoords = 40;
int fieldStartX = 20;
int fieldStartY = 20;
int xOffset = fieldStartX - 10;
int yOffset = fieldStartY - 10;
int pixelWidth = 10;
int pixelHeight = 10;
int updateRight = 850;
int updateBottom = 600;
UINT_PTR MOVE_TIMER;
int moveDelay = 100;
int minDelay = 50;
int difficultyInterval = 10;
int difficultyChange = 1;
std::string gameState;
Snake playsnake;
Point removedPoint;



// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void                gameOver(HWND hWnd);
void                spawnFood(HWND hWnd);
bool                foodFound(Point food, Point snakeHead);
void                eatFood(HWND hWnd);
void                updateField(HWND hWnd, int x, int y);
void                updateSnake(HWND hWnd);
void                updateFood(HWND hWnd);
void                updateScore(HWND hWnd);




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SNEK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SNEK));

    MSG msg;
    //HWND timering;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            /*if (msg.message == WM_TIMER)
            {
                msg.hwnd = timering;
            }*/
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        //moveSnek('r');
        
        
    }

    return (int) msg.wParam;
}


void gameOver(HWND hWnd)
{
    score = 0;
    gameState = "Over";

    moveDelay = 1000;
    playsnake.reset();
    currentDirection = 'r';

    RECT updateRect;
    updateRect.left = 0;
    updateRect.right = updateRight;
    updateRect.top = 0;
    updateRect.bottom = updateBottom;
    InvalidateRect(hWnd, &updateRect, false);
    updateScore(hWnd);
}

void spawnFood(HWND hWnd)
{
    srand(time(NULL));
    int x = rand() % xCoords + 1;
    int y = rand() % yCoords + 1;

    food.setCoords(x, y);
    updateFood(hWnd);
}

bool foodFound(Point food, Point snakeHead)
{
    if ((food.getX() == playsnake.getX(0)) && (food.getY() == playsnake.getY(0)))
    {
        return true;
    }
    return false;
}

void eatFood(HWND hWnd)
{
    if (((playsnake.getLength() % difficultyInterval) == 0) && moveDelay > minDelay)
    {
        moveDelay = moveDelay - difficultyChange;
    }

    playsnake.grow();
    spawnFood(hWnd);
    score++;
    updateScore(hWnd);
}

void updateField(HWND hWnd, int x, int y)
{
    RECT updateRect;
    //GetUpdateRect(hWnd, &updateRect, false);
    updateRect.left = fieldStartX;
    updateRect.right = xCoords * 10 + fieldStartX;
    updateRect.top = fieldStartY;
    updateRect.bottom = yCoords * 10 + fieldStartY;
    InvalidateRect(hWnd, &updateRect, true);
    //RedrawWindow(hWnd, &updateRect, NULL, RDW_UPDATENOW);
}

void updateSnake(HWND hWnd)
{
    RECT updateSnake;
    

    if (isAboveCurrent(playsnake.getHead(), playsnake.getSegment(1)))
    {
        updateSnake.left = playsnake.getSegment(1).getX() * 10 + xOffset;
        updateSnake.right = playsnake.getSegment(1).getX() * 10 + xOffset + 11;
        updateSnake.top = playsnake.getSegment(1).getY() * 10 + yOffset;
        updateSnake.bottom = playsnake.getSegment(1).getY() * 10 + yOffset + 21;
    }
    else if (isBelowCurrent(playsnake.getHead(), playsnake.getSegment(1)))
    {
        updateSnake.left = playsnake.getHead().getX() * 10 + xOffset;
        updateSnake.right = playsnake.getHead().getX() * 10 + xOffset + 11;
        updateSnake.top = playsnake.getHead().getY() * 10 + yOffset;
        updateSnake.bottom = playsnake.getHead().getY() * 10 + yOffset + 21;
    }
    else if (isLeftOfCurrent(playsnake.getHead(), playsnake.getSegment(1)))
    {
        updateSnake.left = playsnake.getSegment(1).getX() * 10 + xOffset;
        updateSnake.right = playsnake.getSegment(1).getX() * 10 + xOffset + 21;
        updateSnake.top = playsnake.getSegment(1).getY() * 10 + yOffset;
        updateSnake.bottom = playsnake.getSegment(1).getY() * 10 + yOffset + 11;
    }
    else if (isRightOfCurrent(playsnake.getHead(), playsnake.getSegment(1)))
    {
        updateSnake.left = playsnake.getHead().getX() * 10 + xOffset;
        updateSnake.right = playsnake.getHead().getX() * 10 + xOffset + 21;
        updateSnake.top = playsnake.getHead().getY() * 10 + yOffset;
        updateSnake.bottom = playsnake.getHead().getY() * 10 + yOffset + 11;
    }

    InvalidateRect(hWnd, &updateSnake, false);
    RedrawWindow(hWnd, &updateSnake, NULL, NULL);

    if (isAboveCurrent(removedPoint, playsnake.getTail()))
    {
        updateSnake.left = playsnake.getTail().getX() * 10 + xOffset - 1;
        updateSnake.right = playsnake.getTail().getX() * 10 + xOffset + 11;
        updateSnake.top = playsnake.getTail().getY() * 10 + yOffset;
        updateSnake.bottom = playsnake.getTail().getY() * 10 + yOffset + 21;
    }
    else if (isBelowCurrent(removedPoint, playsnake.getTail()))
    {
        updateSnake.left = removedPoint.getX() * 10 + xOffset - 1;
        updateSnake.right = removedPoint.getX() * 10 + xOffset + 11;
        updateSnake.top = removedPoint.getY() * 10 + yOffset;
        updateSnake.bottom = removedPoint.getY() * 10 + yOffset + 21;
    }
    else if (isLeftOfCurrent(removedPoint, playsnake.getTail()))
    {
        updateSnake.left = playsnake.getTail().getX() * 10 + xOffset - 1;
        updateSnake.right = playsnake.getTail().getX() * 10 + xOffset + 21;
        updateSnake.top = playsnake.getTail().getY() * 10 + yOffset;
        updateSnake.bottom = playsnake.getTail().getY() * 10 + yOffset + 11;
    }
    else if (isRightOfCurrent(removedPoint, playsnake.getTail()))
    {
        updateSnake.left = removedPoint.getX() * 10 + xOffset - 1;
        updateSnake.right = removedPoint.getX() * 10 + xOffset + 21;
        updateSnake.top = removedPoint.getY() * 10 + yOffset;
        updateSnake.bottom = removedPoint.getY() * 10 + yOffset + 11;
    }

    InvalidateRect(hWnd, &updateSnake, false);
    UpdateWindow(hWnd);
    //RedrawWindow(hWnd, &updateSnake, NULL, RDW_INTERNALPAINT);
}

void updateFood(HWND hWnd)
{
    RECT updateFood;
    updateFood.left = food.getX() * 10 + xOffset;
    updateFood.right = food.getX() * 10 + xOffset + 10;
    updateFood.top = food.getY() * 10 + yOffset;
    updateFood.bottom = food.getY() * 10 + yOffset + 10;
    InvalidateRect(hWnd, &updateFood, false);
}

void updateScore(HWND hWnd)
{
    RECT updateText;
    updateText.left = 400;
    updateText.right = 500;
    updateText.top = 440;
    updateText.bottom = 500;
    InvalidateRect(hWnd, &updateText, false);
}



void drawLine(HDC hdc, int startX, int startY, int endX, int endY, int r, int g, int b)
{
    //SetPixel(hdc, startX, startY, RGB(r, g, b));
    //SetPixel(hdc, endX, endY, RGB(r, g, b));
    if (startX == endX)
    {
        for (int i = startY; i < endY; i++)
        {
            SetPixel(hdc, startX + fieldStartX, i, RGB(r, g, b));
        }
    }
    else if (startY == endY)
    {
        for (int i = startX; i < endX; i++)
        {
            SetPixel(hdc, i + fieldStartY, startY, RGB(r, g, b));
        }
    }
    else
    { }
}

void paintSnekHead(HDC hdc, char direction, Point seg)
{
    if (direction == 'r')
    {
        drawLine(hdc, seg.getX() * 10 + xOffset, seg.getY() * 10 + yOffset, (seg.getX() + 1) * 10 + xOffset, seg.getY() * 10 + yOffset, 0, 0, 0);
        drawLine(hdc, (seg.getX() + 1) * 10 + xOffset, seg.getY() * 10 + yOffset, (seg.getX() + 1) * 10 + xOffset, (seg.getY() + 1) * 10 + yOffset, 0, 0, 0);
        drawLine(hdc, seg.getX() * 10 + xOffset, (seg.getY() + 1) * 10 + yOffset, (seg.getX() + 1) * 10 + xOffset, (seg.getY() + 1) * 10 + yOffset, 0, 0, 0);
    }
}




//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SNEK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SNEK);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   /*HWND quitBTN = CreateWindowW(
       L"BUTTON",  // Predefined class; Unicode assumed 
       L"Quit",      // Button text 
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
       10,         // x position 
       500,         // y position 
       40,        // Button width
       20,        // Button height
       hWnd,     // Parent window
       (HMENU)1,       // Button ID
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL); */     // Pointer not needed.

   /*HWND testTBN = CreateWindowW(L"BUTTON", L"Test", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 500, 40, 20, hWnd, (HMENU)2,(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL); */

   
   spawnFood(hWnd);
   SetTimer(hWnd, MOVE_TIMER, moveDelay, (TIMERPROC)0);
   gameState = "Waiting";

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            int wm2 = HIWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                //return DefWindowProc(hWnd, message, wParam, lParam);
                break;
            }

            switch (wm2)
            {
            case BN_CLICKED:
                if (wmId == 1) 
                {
                    DestroyWindow(hWnd);
                }
                if (wmId == 2)
                {
                    spawnFood(hWnd);
                }
                else
                {
                    KillTimer(hWnd, MOVE_TIMER);
                    playsnake.reset();
                    SetTimer(hWnd, MOVE_TIMER, moveDelay, (TIMERPROC)0);
                }
                break;
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            SelectObject(hdc, GetStockObject(DC_PEN));
            SetDCPenColor(hdc, RGB(0, 0, 0));
            SelectObject(hdc, GetStockObject(DC_BRUSH));
            SetDCBrushColor(hdc, RGB(240,240,240));

            //+/- 1 to make the field border just outside the outer snake and food pixels instead of inside them
            Rectangle(hdc, fieldStartX - 1, fieldStartY - 1, xCoords * 10 + fieldStartX + 2, yCoords * 10 + fieldStartY + 2);
            //srand(time(NULL));
            SetDCBrushColor(hdc, RGB(0, 0, 255));

            //Rectangle(hdc,playsnake.getHead().getX() * 10 + xOffset,playsnake.getHead().getY() * 10 + yOffset, (playsnake.getHead().getX() + 1) * 10 + xOffset, (playsnake.getHead().getY() + 1) * 10 + yOffset);

            drawSnakeHead(hdc, currentDirection, playsnake.getHead(), xOffset, yOffset);

            for (int i = 1; i < playsnake.getLength() - 1; i++)
            {drawSnakeBodySegment(hdc, playsnake.getSegment(i), playsnake.getSegment(i - 1), playsnake.getSegment(i + 1), xOffset, yOffset);
            }

            drawSnakeTail(hdc, playsnake.getTail(), playsnake.getSegment(playsnake.getLength()-2), playsnake.getSegment(playsnake.getLength() - 3),xOffset,yOffset);
            

            SetDCBrushColor(hdc, RGB(255, 0, 0));
            SetDCPenColor(hdc, RGB(0, 0, 0));

            Ellipse(hdc, food.getX() * 10 + fieldStartX - 10, food.getY() * 10 + fieldStartY - 10, (food.getX() + 1) * 10 + fieldStartX - 10, (food.getY() + 1) * 10 + fieldStartY - 10);

            
            
            //TextOut(hdc, 500, 500, wScore, 4);
            RECT clientRect;
            GetClientRect(hWnd, &clientRect);
            clientRect.top = 450;
            clientRect.left = 400;

            std::wstring scoreTm = std::to_wstring(score);
            std::wstring scBuf;
            if (score < 10)
            {
                scBuf = L"Score: 000";
            }
            else if (score < 100)
            {
                scBuf = L"Score: 00";
            }
            else if (score < 1000)
            {
                scBuf = L"Score: 0";
            }
            scoreTm = scBuf + scoreTm;
            LPCWSTR wScore = scoreTm.c_str();
            DrawText(hdc,wScore,-1,&clientRect, DT_SINGLELINE);
            

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
            case VK_RIGHT: // Process the RIGHT ARROW key. 
                if (gameState == "Waiting")
                {
                    gameState = "Playing";
                }
                if (currentDirection != 'l')
                {
                    currentDirection = 'r';
                }
                break;
            case VK_LEFT: // Process the LEFT ARROW key. 
                if (gameState == "Waiting")
                {
                    gameState = "Playing";
                }

                if (currentDirection != 'r')
                {
                    currentDirection = 'l';
                }
                break;
            case VK_UP: // Process the UP ARROW key. 
                if (gameState == "Waiting")
                {
                    gameState = "Playing";
                }
                if (currentDirection != 'd')
                {
                    currentDirection = 'u';
                }
                break;
            case VK_DOWN: // Process the DOWN ARROW key. 
                if (gameState == "Waiting")
                {
                    gameState = "Playing";
                }
                if (currentDirection != 'u')
                {
                    currentDirection = 'd';
                }
                break;
            case VK_ESCAPE: // Process the ESCAPE key. 
                DestroyWindow(hWnd);
                break;
        }
        break;
    case WM_TIMER:
    {
        if (gameState == "Playing")
        {
            //moveSnek(currentDirection, hWnd);
            removedPoint = playsnake.getTail();
            playsnake.move(currentDirection);

            if (playsnake.hitSelf() || playsnake.hitWall(xCoords,yCoords))
            {
                gameOver(hWnd);
            } 

            if (foodFound(food,playsnake.getHead()))
            {
                eatFood(hWnd);
            }

            //updateField(hWnd, 1, 1);
            updateSnake(hWnd);
        }
        else if (gameState == "Over")
        {
            gameState = "Waiting";
            moveDelay = 500;
        }
        else if (gameState == "Waiting")
        {
            //Wait for movement input
        }
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
