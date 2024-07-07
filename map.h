#ifndef MAP
#define MAP
#include <iostream>

enum Direction{null, left, up, right, down};

class Map
{
public:
    static void create(int w, int h);
    
    static void spaceCurrent(int&, int&, int&);

    static int row;
    static int column;
    static int** matrix;
};

#endif