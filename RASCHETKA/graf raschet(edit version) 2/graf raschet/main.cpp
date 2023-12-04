#include <iostream>
#include "graff.h"

using namespace std;



int main() {

    GraphRidiculousness g("../file.txt");

    
    cout << "Minimum distances of graph: " << g.minimumDistancePeripheralNodes() << endl;
    cout << "Average distances of graph: " << g.averageDistancePeripheralNodes() << endl;

    return 0;
}