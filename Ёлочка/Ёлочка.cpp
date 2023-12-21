#include <iostream>
#include <cstdlib>
#include "TConsole.h"

using namespace std;

#define X_MAX 118
#define Y_MAX 29
const int inner = 51;
TConsole console;
const int N = 161;
int contour = 51;


struct Point
{
    int x;
    int y;
    unsigned int color;
    Point() { x = 0; y = 0; color = COLOR_WHITE; }
    Point(int x, int y, unsigned int color) { this->x = x; this->y = y; this->color = color; }
    Point(int x, int y) { this->x = x; this->y = y; this->color = COLOR_WHITE; }
};

Point Snow[100] = { Point() };
Point NewYear[130];
Point Garland[148] = { Point(0, 0), Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 3), Point(4, 4), Point(5, 3), Point(6, 2), Point(7, 1), Point(8, 0)};
int I_Tree_Garland[N] = {0};
Point Christmas_tree[N] = { Point(20, 27, COLOR_BROWN), Point(20, 26, COLOR_BROWN), Point(20, 25, COLOR_GREEN), Point(19, 25, COLOR_GREEN),
Point(18, 25, COLOR_GREEN), Point(17, 25, COLOR_GREEN), Point(16, 25, COLOR_GREEN), Point(15, 25, COLOR_GREEN), Point(14, 25, COLOR_GREEN), Point(13, 25, COLOR_GREEN),
Point(12, 25, COLOR_GREEN), Point(11, 25, COLOR_GREEN), Point(10, 25, COLOR_GREEN) };



void Setup()
{
   

    //-------------------------------------------------------- Snow
    int xl = 0, y = 0, xr = 4;
    //
    for (int i = 0; i < 100; i++)
    {
        Snow[i] = Point(rand() % (X_MAX - 1 + 1) + 1, rand() % (Y_MAX - 3 - 0 + 1) + 0);
      
  
    }
    //-------------------------------------------------------- Snow

    //-------------------------------------------------------- Christmas_tree
    xr = 31;
    xl = 11, y = 24;
    for (int i = 13; i < 23; i++)
    {
        Christmas_tree[i] = Point(xl, y, COLOR_GREEN);
        Christmas_tree[i + 10] = Point(xr, y, COLOR_GREEN);
        xl++;
        xr--;
        y--;
    }
    xr = 32;
    for (int i = 33; i < 45; i++)
    {
        Christmas_tree[i] = Point(xr, 25, COLOR_GREEN);
        xr--;
    }


    Christmas_tree[45] = Point(xl++, y, COLOR_YELLOW);
    Christmas_tree[46] = Point(xl, y, COLOR_YELLOW);
    xl -= 2;
    Christmas_tree[47] = Point(xl++, y--, COLOR_YELLOW);
    Christmas_tree[48] = Point(xl, y, COLOR_YELLOW);
    Christmas_tree[49] = Point(21, 27, COLOR_BROWN);
    Christmas_tree[50] = Point(21, 26, COLOR_BROWN);

    xl = 12;
    xr = 30;
    y = 24;
    int i = 51;
    int j = 0;
    int step = 1;

    while (y > 14)
    {
        int color;
        if (xl % (rand() % (4 - 2 + 1) + 2) == 0)
        {
            color = rand() % (COLOR_LIGHTMAGENTA - COLOR_CYAN + 1) + COLOR_CYAN;
            I_Tree_Garland[j++] = i;
            I_Tree_Garland[j++] = i + 1;
        }
        else color = COLOR_GREEN;
        Christmas_tree[i++] = Point(xr, y, color);
        Christmas_tree[i++] = Point(xl, y, color);
        xr--;
        xl++;
        if (xr < xl)
        {
            y--;
            xl = 12 + step;
            xr = 30 - step;
            step++;
        }

    }
  
    //-------------------------------------------------------- Christmas_tree



    //-------------------------------------------------------- Graland
    j = 0;
    for (int i = 0; i < 138; i++)
    {
        Garland[i + 10] = Point(Garland[i].x+8, Garland[i].y);
    }
    //-------------------------------------------------------- Graland



    //-------------------------------------------------------- NewYear
    int x = 45;
    y = 13;
    for (int i = 0; i < 6; i++)
    {
        NewYear[i] = Point(x, y);
        NewYear[i + 6] = Point(x + 7, y);
        NewYear[i + 12] = Point(x + 10, y--);
    }
    x = 55, y = 18;
    xl = 52, xr = 58;
    for (int i = 18; i < 27; i++)
    {
        
        NewYear[i++] = Point(xl++, y - 3);
        NewYear[i++] = Point(xr--, y - 3);
        NewYear[i] = Point(x, y++);
    }
    i = 27, x = 60;
    int y1 = 13;
    y = 20;
    while (y > 14)
    {
        if (y % 2) 
        {
            NewYear[i++] = Point(x, y);
            NewYear[i++] = Point(x + 20, y);
        }
        else
        {
            NewYear[i++] = Point(x, y);
            NewYear[i++] = Point(x + 20, y);
        }
        y--;
    }
    x = 46, y = 8, xl = 56, y1 = 11;
    while (x < 52)
    {
        NewYear[i++] = Point(x++, y++);
        if (xl < 62)
        {
            if (xl % 2 == 0)
            {
                NewYear[i++] = Point(xl + 5, y1 + 7);
                NewYear[i++] = Point(xl++, y1);
            }
            else
            {
                NewYear[i++] = Point(xl + 5, y1 + 4);
                NewYear[i++] = Point(xl, y1 - 3);
                NewYear[i++] = Point(xl + 5, y1 + 9);
                NewYear[i++] = Point(xl++, y1 + 2);
            }
        }
    }
    xl = 56;
    while (xl < 63)
    {
        if (xl % 2)
        {
            NewYear[i++] = Point(xl + 5, y1 + 7);
            NewYear[i++] = Point(xl++, y1);
        }
        else {

            NewYear[i++] = Point(xl + 5, y1 + 4);
            NewYear[i++] = Point(xl, y1 - 3);
            NewYear[i++] = Point(xl + 5, y1 + 9);
            NewYear[i++] = Point(xl++, y1 + 2);
        }
    }

    // W
    xl = xl + 2, xr = xl + 4; // 7
    y = 8, y1 = 13;
    int count = 0;
    while (count < 2)
    {
        
        if (y % 2 == 0)
        {
            NewYear[i++] = Point(xl++, y);
            NewYear[i++] = Point(xr++, y1);
        }
        y++;
        y1--;
        
       // y += 2;
       // y1 -= 2;
        if (y > 13)
        {
            NewYear[i++] = Point(xl, y - 1);
            y = 8, y1 = 13, xl = xr, xr += 4;
            count++;
        }
    }
    xr = 69;
    NewYear[i++] = Point(xr, y + 4);
    NewYear[i++] = Point(xr + 10, y);
   // NewYear[i++] = Point(xr + 2, y + 2);
    // W

    // A
    xl = 69, xr = 69 + 8;
    y = 20;
    while (y > 15) NewYear[i++] = Point(xl++, y--);
   
    NewYear[i++] = Point(xl - 1, y);
    y = 20;
    while (y > 16) NewYear[i++] = Point(xr--, y--);
   
    NewYear[i++] = Point(xl - 2, 18);
    NewYear[i++] = Point(xl - 1, 18);
    NewYear[i++] = Point(xl, 18);
    // A


    // R
    xl = 81, y = 15;
    while (87 > xl) NewYear[i++] = Point(xl++, y);
    y++;
    NewYear[i++] = Point(xl, y++);
    NewYear[i++] = Point(xl--, y++);
    while (80 < xl) NewYear[i++] = Point(xl--, y);
    NewYear[i++] = Point(xl+3, y+1);
    NewYear[i++] = Point(xl+5, y+2);

    // R
    //-------------------------------------------------------- NewYear
}

bool CheckPosition(int i)
{
    int xl = 10, xr = 32, y = Y_MAX-4;
    
    
    for (int j = 0; j < 24; j++)
    {

        if (Snow[i].x >= xl && Snow[i].x <= xr && Snow[i].y == y) return false;
        if (i > 1)
        {
            xl++;
            xr--;
            y--;
        }
    }
    for (int j = 45; j < 50; j++)
        if (Snow[i].x == Christmas_tree[j].x && Snow[i].y == Christmas_tree[j].y) return false;

    for (int j = 0; j < size(Garland); j++)
    {
        if (j < size(NewYear))
        {
            if (Snow[i].x == NewYear[j].x && Snow[i].y == NewYear[j].y) return false;
        }
        if (Snow[i].x == Garland[j].x && Snow[i].y == Garland[j].y)  return false;
    }
    return true;
}

void Move_Snow()
{
   
    for (int i = 0; i < size(Snow); i++)
    {
        
        
       if (CheckPosition(i))
        {
            console.GotoXY(Snow[i].x, Snow[i].y);
            printf(" ");
       }
        if (rand() % 2) Snow[i].x = Snow[i].x + rand() % (3 - 1 + 1) + 1;
        else Snow[i].x = Snow[i].x - (rand() % (3 - 1 + 1) + 1);
        if (rand() % 2) Snow[i].y = Snow[i].y + rand() % (3 - 1 + 1) + 1;
        else Snow[i].y = Snow[i].y + rand() % (3 - 1 + 1) + 1;
        
        if (Snow[i].y >= Y_MAX - 1) Snow[i] = Point(rand() % (X_MAX - 0 + 1) + 1, 0);
        if (Snow[i].x > X_MAX || Snow[i].x < 0) Snow[i] = Point(rand() % (X_MAX - 0 + 1) + 1, 0);
    }
}

void Change_Garland()
{
    int i = 0; 
    while (I_Tree_Garland[i] != 0)
    {
        Garland[i].color = rand() % (COLOR_LIGHTMAGENTA - COLOR_CYAN + 1) + COLOR_CYAN;
        Christmas_tree[I_Tree_Garland[i++]].color = rand() % (COLOR_LIGHTMAGENTA - COLOR_CYAN + 1) + COLOR_CYAN;
        
    }
    while (i < size(Garland)) Garland[i++].color = rand() % (COLOR_LIGHTMAGENTA - COLOR_CYAN + 1) + COLOR_CYAN;
        
    
}

void Print_Christmas_tree()
{
    for (int i = 0; i < size(Christmas_tree); i++)
    {   
     
        
        console.TextColor(Christmas_tree[i].color);
        console.GotoXY(Christmas_tree[i].x, Christmas_tree[i].y);
        if (i > 50 && Christmas_tree[i].color != COLOR_GREEN) {
            cout << (char)248; 
        }
        else cout << '&';
    }
}

void Print_Garland()
{
    for (int i = 0; i < size(Garland); i++)
    {
        console.GotoXY(Garland[i].x, Garland[i].y);
        console.TextColor(Garland[i].color);
        cout << '%';
    }
}

void Print_Snow()
{
    console.TextColor(COLOR_WHITE);
    for (int i = 0; i <= X_MAX*2+1; i++)
    {
        if (i <= X_MAX) console.GotoXY(i, Y_MAX);
        else console.GotoXY((i - X_MAX-1), Y_MAX - 1);
        cout << '#';
    }



    for (int i = 0; i < size(Snow); i++)
    {
        if (CheckPosition(i))
        {
            console.GotoXY(Snow[i].x, Snow[i].y);
            cout << '*';
        }
    }

  
}

void Print_NewYear()
{
   
    for (int i = 0; i < size(NewYear); i++)
    {
        console.TextColor(COLOR_YELLOW);
        console.GotoXY(NewYear[i].x, NewYear[i].y);
        cout << '?';
    }
}

void FirstPrint()
{
    
    for (int i = 0 ;i < N; i++)
    {
        if (i < size(Garland))
        {
            console.GotoXY(Garland[i].x, Garland[i].y);
            console.TextColor(Garland[i].color);
            cout << '%';
        }
        Sleep(10);
        console.TextColor(Christmas_tree[i].color);
        console.GotoXY(Christmas_tree[i].x, Christmas_tree[i].y);
        if (i > 50 && Christmas_tree[i].color != COLOR_GREEN) cout << (char)248;
        else cout << '&';
        
        if (i < size(NewYear))
        {
            console.TextColor(COLOR_YELLOW);
            console.GotoXY(NewYear[i].x, NewYear[i].y);
            console.TextColor(Garland[i].color);
            cout << '?';
        }
    }
   
}

int main()
{
    srand(time(NULL));

    Setup();

   // FirstPrint();
    
    while (true)
    {
        
        console.Window(X_MAX + 2, Y_MAX + 1);

        Print_Snow();
        console.Delay(60);
        Print_Christmas_tree();
        Print_Garland();
        Print_NewYear();
        Change_Garland();
       Move_Snow();
    }

  
    return 0;
}

