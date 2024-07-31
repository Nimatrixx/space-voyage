#include "navigator.h"
#include <iostream>
using namespace std;

Navigator::Navigator()
{
    matrix = new SpaceCraft *[Map::row];
    for(int i = 0; i < Map::row; i++)
    {
        matrix[i] = new SpaceCraft[Map::column];
    }
}

void Navigator::setBase(Base b)
{
    base = b;

    for(int i = 0; i < Map::row; i++)
    {
        for(int j = 0; j < Map::column; j++)
        {
            matrix[i][j] = SpaceCraft();
        }
    }
}

bool Navigator::isNewOneBetter(SpaceCraft& newOne)
{
    SpaceCraft firstOne = matrix[newOne.getX()][newOne.getY()];

    if(firstOne.getX() == -1)
    {
        return 1;
    }
    if(base == Base::NUN)
    {
        return 0;
    }else if(base == Base::ENERGY)
    {
        if(firstOne.getEnergy() < newOne.getEnergy())
        {
            return 1;
        }else
        {
            return 0;
        }
    }else if(base == Base::TIME)
    {
        if(firstOne.getCurrentTime() > newOne.getCurrentTime())
        {
            return 1;
        }else
        {
            return 0;
        }
    }

    return 0;
}

void Navigator::navigate(SpaceCraft spaceCraft)
{
    if(isNewOneBetter(spaceCraft))
    {
        matrix[spaceCraft.getX()][spaceCraft.getY()] = spaceCraft;
    }else
    {
        return;
    }
   
    cost++;

    SpaceCraft l = spaceCraft;
    if(l.move(Prosedure::moveL))
    {
        navigate(l);
    }
    SpaceCraft u = spaceCraft;
    if(u.move(Prosedure::moveU))
    {
        navigate(u);
    }
    SpaceCraft r = spaceCraft;
    if(r.move(Prosedure::moveR))
    {
        navigate(r);
    }
    SpaceCraft d = spaceCraft;
    if(d.move(Prosedure::moveD))
    {
        navigate(d);
    }

    SpaceCraft sc = spaceCraft;
    if(sc.rideProsedure())
    {
        navigate(sc);
    }
}

SpaceCraft Navigator::getFinalSpaceCraft()
{
    for(int i = 0; i < Map::row; i++)
    {
        for(int j = 0; j < Map::column; j++)
        {
            if(Map::matrix[i][j] == 5)return matrix[i][j];
        }
    }
    
    SpaceCraft nunSpaceCraft;
    return nunSpaceCraft;
}

void Navigator::printMap()
{
    for(int i = 0; i < Map::row; i++)
    {
        for(int j = 0; j < Map::column; j++)
        {
            if(base == Base::NUN || base == Base::ENERGY)
            {
                cout << matrix[i][j].getEnergy() << " ";
            }
            else 
            {
                cout << matrix[i][j].getCurrentTime() << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

long long int Navigator::getAlgoCost()
{
    return cost;
}