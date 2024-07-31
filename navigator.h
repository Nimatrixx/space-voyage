#ifndef NAVIGATOR
#define NAVIGATOR
#include "space_craft.h"

enum Base{ NUN, ENERGY, TIME};

class Navigator
{
    Base base = Base::TIME;
    SpaceCraft** matrix;

    long long int cost;

public:

    Navigator();
    void setBase(Base);
    bool isNewOneBetter(SpaceCraft&);
    void navigate(SpaceCraft);
    SpaceCraft getFinalSpaceCraft();
    void printMap();
    long long int getAlgoCost();
};
#endif