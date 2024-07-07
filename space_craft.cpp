#include "space_craft.h"
#include <iostream>
using namespace std;

SpaceCraft::SpaceCraft(): x(-1), y(-1), energy(0), currentTime(0){}

SpaceCraft::SpaceCraft(int x, int y, int energy)
{
    this->x = x;
    this->y = y;
    this->energy = energy;
    currentTime = 0;
}

int SpaceCraft::getX()
{
    return x;
}

int SpaceCraft::getY()
{
    return y;
}

int SpaceCraft::getEnergy()
{
    return energy;
}

int SpaceCraft::getCurrentTime()
{
    return currentTime;
}

void SpaceCraft::consumeEnergy(int a)
{
    energy -= a;
    energy = max(energy, 0);
}

void SpaceCraft::increaseTime(int t)
{
    currentTime += t;
}

void SpaceCraft::updatePath(Prosedure newP)
{
    path.push_back(newP);
}

bool SpaceCraft::move(Prosedure p)
{
    if(p == Prosedure::moveL)
    {
        if(y == 0)return 0;
        if(Map::matrix[x][y-1] == 3 || Map::matrix[x][y-1] == 2)return 0;
        y = y-1;
    }else if(p == Prosedure::moveU)
    {
        if(x == 0)return 0;
        if(Map::matrix[x-1][y] == 3 || Map::matrix[x-1][y] == 2)return 0;
        x = x-1;
    }else if(p == Prosedure::moveR)
    {
        if(y == Map::column-1)return 0;
        if(Map::matrix[x][y+1] == 3 || Map::matrix[x][y+1] == 2)return 0;
        y = y+1;
    }else if(p == Prosedure::moveD)
    {
        if(x == Map::row-1)return 0;
        if(Map::matrix[x+1][y] == 3 || Map::matrix[x+1][y] == 2)return 0;
        x = x+1;
    }
    
    consumeEnergy(1);
    increaseTime(5);
    updatePath(p);

    return 1;
}

bool SpaceCraft::rideProsedure()
{
    if(Map::matrix[x][y] != 1)return 0;

    int distance = 0;
    Map::spaceCurrent(x,y,distance);

    consumeEnergy(2*distance);
    increaseTime(1*distance);
    updatePath(Prosedure::ride);

    return 1;
}

void SpaceCraft::printPath()
{
    char map[Map::row][Map::column];
    
    for(int i = 0; i < Map::row; i++)
    {
        for(int j = 0; j < Map::column; j++)
        {
            map[i][j] = char(Map::matrix[i][j]+48);
        }
    }

    int aX = x, aY = y;
    for(int i = path.size()-1; i >= 0; --i)
    {
        switch(path[i])
        {
            case 0:
                continue;
            case 1:
                map[aX][aY] = '-';
                aY++;
                break;
            case 2:
                map[aX][aY] = '|';
                aX++;
                break;
            case 3:
                map[aX][aY] = '-';
                aY--;
                break;
            case 4:
                map[aX][aY] = '-';
                aX--;
                break;
            case 5:
                map[aX][aY] = 'r';
                int distance = 0;
                Map::spaceCurrent(aX,aY,distance);
                break;
        }
    }
    for(int i = 0; i < Map::row; i++)
    {
        for(int j = 0; j < Map::column; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}