#ifndef MAP
#define MAP
#include <iostream>

enum Direction{null, left, up, right, down};

class Map
{
public:
    static void create(int w, int h);
    
    static void spaceCurrent(int&, int&, int&);

    static void spaceObject(int&, int&, int&);

    static void wormhole(int& x, int& y, int& distance);

    static int row;
    static int column;
    static int** matrix;
};

#endif