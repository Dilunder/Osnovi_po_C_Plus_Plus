#include <iostream>
#include <cmath>
#include "vector.h"

using namespace std;

Vector::Vector(){
    mas = 0;
    v1 = v2 = {0, 0};
};

Vector::~Vector() {}

double Vector::square() {
    return 0;
}

double Vector::perimeter() {
    return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

double Vector::mass() const {
    return mas;
}

CVector2D Vector::position() {
    return {(v1.x + v2.x) / 2, (v1.y + v2.y) / 2};
}

bool Vector::operator==(const IPhysObject &ob) const {
    return this->mas == ob.mass();
}

bool Vector::operator<(const IPhysObject &ob) const {
    return this->mas < ob.mass();
}

void Vector::draw() {
    cout << name << endl;
    cout << "Cordinates: " << endl;
    cout << "V1: " << "("<< v1.x << ", " << v1.y << ")" << endl;
    cout << "V2: " << "("<< v2.x << ", " << v2.y << ")" << endl;
    cout << "Center: " << "(" << position().x << ", " << position().y << ")" << endl;
    cout << "Square: " << square() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

void Vector::initFromDialog() {
    cout << "Mass = ";
    cin >> mas;
    cout << "x of V1 = ";
    cin >> v1.x;
    cout << "y of V1 = ";
    cin >> v1.y;
    cout << "x of V2 = ";
    cin >> v2.x;
    cout << "y of V2 = ";
    cin >> v2.y;
}

const char *Vector::classname() {
    return name;
}

unsigned int Vector::size() {
    return sizeof(*this);
}
