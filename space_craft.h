#ifndef SPACECRAFT
#define SPACECRAFT
#include "map.h"
#include <vector>

enum Prosedure{nill, moveL, moveU, moveR, moveD, ride, orbit, wormhole};

class SpaceCraft
{
    int x;
    int y;
    int currentTime;
    int energy;
    std::vector<Prosedure> path;

    void increaseTime(int t);
    void consumeEnergy(int a);
    void updatePath(Prosedure p);

public:
    SpaceCraft();
    SpaceCraft(int x, int y, int energy);

    int getX();
    int getY();
    int getEnergy();
    int getCurrentTime();

    bool move(Prosedure p);
    bool rideProsedure();
    bool orbitProcedure();
    bool wormholeProcedure();

    // void orbitProcedure();
    // void teleportProcedure();

    void printPath();

};
#endif