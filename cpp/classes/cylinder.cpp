#include "cylinder.h"

Cylinder::Cylinder () = default;
Cylinder::Cylinder (double bh, double h) {
    this->base_radius = bh;
    this->height = h;
}

// Getters
double Cylinder::get_base_radius() {
    return base_radius;
}
double Cylinder::get_height() {
    return height;
}

// Setters
void Cylinder::set_base_radius(double bh) {
    base_radius = bh;
}
void Cylinder::set_height(double h) {
    height = h;
}

// Functions (methods) 
double Cylinder::volume() {
    return PI * base_radius * height;
}