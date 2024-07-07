#include "space_voyage.h"
using namespace std;

void SpaceVoyage::run()
{
    int m, n;
    int x, y;
    int energy;

    cin >> n >> m;
    cin >> x >> y;
    cin >> energy;

    Map::create(n, m);
    SpaceCraft spaceCraft(x,y,energy);

    Navigator nav;

    //nun base
    cout << "Nun Base :\n";
    nav.setBase(Base::NUN);

    nav.navigate(spaceCraft);
    cout << "\talgorithm cost : " << nav.getAlgoCost() << endl;
    SpaceCraft finalCraft = nav.getFinalSpaceCraft();
    cout << "\tenergy: " << finalCraft.getEnergy() << endl;
    cout << "\ttime: " << finalCraft.getCurrentTime() << endl;
    finalCraft.printPath();

    //energy base
    cout << "Energy Base :\n";
    nav.setBase(Base::ENERGY);

    nav.navigate(spaceCraft);
    cout << "\talgorithm cost : " << nav.getAlgoCost() << endl;
    finalCraft = nav.getFinalSpaceCraft();
    cout << "\tenergy: " << finalCraft.getEnergy() << endl;
    cout << "\ttime: " << finalCraft.getCurrentTime() << endl;
    finalCraft.printPath();

    //time base
    cout << "Time Base :\n";
    nav.setBase(Base::TIME);

    nav.navigate(spaceCraft);
    cout << "\talgorithm cost : " << nav.getAlgoCost() << endl;
    finalCraft = nav.getFinalSpaceCraft();
    cout << "\tenergy: " << finalCraft.getEnergy() << endl;
    cout << "\ttime: " << finalCraft.getCurrentTime() << endl;
    finalCraft.printPath();

}