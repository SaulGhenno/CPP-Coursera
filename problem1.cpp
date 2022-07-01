/*
    The following program computes
    the probability for dice possibilities

*/

#include <iostream> //drops .h still available
#include <cstdlib>
#include <ctime>
using namespace std;
const int sides = 6; //replaces many sharp defines
inline int r_sides(){return (rand() % sides + 1);}

