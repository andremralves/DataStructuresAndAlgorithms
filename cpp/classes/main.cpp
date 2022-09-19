#include <iostream>
#include "cylinder.h"


int main(int argc, char const *argv[])
{
    // Creating Cylinder objects
    Cylinder cylinder1; // Uses the default constructor
    Cylinder cylinder2(10, 10);

    // Using getters and setters
    cylinder1.set_base_radius(5);
    cylinder1.set_height(5);
    std::cout << "Cylinder1 base radius: " << cylinder1.get_base_radius() << std::endl;
    std::cout << "Cylinder1 height: " << cylinder1.get_height() << std::endl;

    // Printing
    std::cout << "Cylinder1 volume: " << cylinder1.volume() << std::endl;
    std::cout << "Cylinder2 volume: " << cylinder2.volume() << std::endl;
    return 0;
}
