#include "map.h"
using namespace std;

void Map::create(int r, int c)
{
    row = r;
    column = c;

    matrix = new int *[r];
    for(int i = 0; i < r; i++)
        matrix[i] = new int[c];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void Map::spaceCurrent(int& x, int& y, int& distance)
{
    Direction lastDir;
    bool end = false;
    while(!end)
    {
        if(y-1 >= 0 && Map::matrix[x][y-1] == 2 && lastDir != Direction::left)
        {
            y = y-1;
            lastDir = Direction::right;
        }else if(x-1 >= 0 && Map::matrix[x-1][y] == 2 && lastDir != Direction::up)
        {
            x = x-1;
            lastDir = Direction::down;
        }else if(y+1 < Map::column-1 && Map::matrix[x][y+1] == 2 && lastDir != Direction::right)
        {
            y = y+1;
            lastDir = Direction::left;
        }else if(x+1 < Map::row-1 && Map::matrix[x+1][y] == 2 && lastDir != Direction::down)
        {
            x = x+1;
            lastDir = Direction::up;
        }else
        {
            end = 1;

            if(x-1 >= 0 && Map::matrix[x-1][y] == 1)
            {
                x = x-1;
            }else if(y-1 >= 0 && Map::matrix[x][y-1] == 1)
            {
                y = y-1;
            }else if(x+1 < Map::row-1 && Map::matrix[x+1][y] == 1)
            {
                x = x+1;
            }else if(y+1 < Map::column-1 && Map::matrix[x][y+1] == 1)
            {
                y = y+1;
            }
        }
        distance++;
    }
}

//////////////////////////////////
void Map::spaceObject(int& x, int& y, int& distance)
{
    Direction lastDir;
    bool end = false;
    while(!end)
    {
        if(y-1 >= 0 && Map::matrix[x][y-1] == 3 && lastDir != Direction::left)
        {
            y = y-1;
            lastDir = Direction::right;
        }else if(x-1 >= 0 && Map::matrix[x-1][y] == 3 && lastDir != Direction::up)
        {
            x = x-1;
            lastDir = Direction::down;
        }else if(y+1 < Map::column-1 && Map::matrix[x][y+1] == 3 && lastDir != Direction::right)
        {
            y = y+1;
            lastDir = Direction::left;
        }else if(x+1 < Map::row-1 && Map::matrix[x+1][y] == 3 && lastDir != Direction::down)
        {
            x = x+1;
            lastDir = Direction::up;
        }else
        {
            end = 1;

            if(x-1 >= 0 && Map::matrix[x-1][y] == 0)
            {
                x = x-1;
            }else if(y-1 >= 0 && Map::matrix[x][y-1] == 0)
            {
                y = y-1;
            }else if(x+1 < Map::row-1 && Map::matrix[x+1][y] == 0)
            {
                x = x+1;
            }else if(y+1 < Map::column-1 && Map::matrix[x][y+1] == 0)
            {
                y = y+1;
            }
        }
        distance++;
    }
}




/// ///////////////////////////
void Map::wormhole(int& x, int& y, int& distance)
{
    bool end = false;
    while(!end)
    {
        // Checking adjacent cells for a wormhole part (4)
        if(y-1 >= 0 && Map::matrix[x][y-1] == 4)
        {
            y = y-1;
        }
        else if(x-1 >= 0 && Map::matrix[x-1][y] == 4)
        {
            x = x-1;
        }
        else if(y+1 < Map::column && Map::matrix[x][y+1] == 4)
        {
            y = y+1;
        }
        else if(x+1 < Map::row && Map::matrix[x+1][y] == 4)
        {
            x = x+1;
        }
        else
        {
            end = true;

            // Find the corresponding wormhole exit
            for(int i = 0; i < Map::row; ++i)
            {
                for(int j = 0; j < Map::column; ++j)
                {
                    if(Map::matrix[i][j] == 4 && (i != x || j != y))
                    {
                        x = i;
                        y = j;
                        break;
                    }
                }
                if(end) break;
            }
        }
        distance++;
    }
}








///  //////////////////////


int Map::column;
int Map::row;
int** Map::matrix;
