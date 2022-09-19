#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class Cylinder {
    // Propperties
    private:
        double base_radius;
        double height;
    // Methods
    public:
        // Constructors
        Cylinder ();
        Cylinder (double bh, double h);

        // Getters
        double get_base_radius();
        double get_height();
        // Setters
        void set_base_radius(double bh);
        void set_height(double h);
        double volume();

};

#endif