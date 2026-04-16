#include "Shape.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Shape::display() const {
    cout << "Shape" << endl;
}

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::getArea() const {
    return width * height;
}

void Rectangle::display() const {
    cout << fixed << setprecision(1);
    cout << "Rectangle (" << width << " x " << height << ")" << endl;
}

Circle::Circle(double r) : radius(r) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

void Circle::display() const {
    cout << fixed << setprecision(1);
    cout << "Circle (radius: " << radius << ")" << endl;
}