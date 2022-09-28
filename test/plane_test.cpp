#include <iostream>
#include "plane.hpp"

int main()
{
    //   checking of default constructor
    Plane plane1 {};
    Plane plane2 {0.0, 0.0, 0.0, 1.0};

    Plane plane3 = {1.1, 1.0, 1.0, 2.0};

    return 0;
}