#include <iostream>
#include <cmath>
#include "six_edges.h"

using namespace std;

Hexagon::Hexagon() {
    mas = 0;
    v1 = v2 = v3 = v4 = v5 = v6 = {0, 0};
}

Hexagon::~Hexagon() {}

double Hexagon::square() {
    return 3 * sqrt(3) * pow(sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)), 2) / 2;
}

double Hexagon::perimeter() {
    return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)) * 6;
}

double Hexagon::mass() const {
    return mas;
}

CVector2D Hexagon::position() {
    return {(v1.x + v4.x) / 2, (v1.y + v4.y) / 2};
}

bool Hexagon::operator==(const IPhysObject &ob) const {
    return this->mas == ob.mass();
}

bool Hexagon::operator<(const IPhysObject &ob) const {
    return this->mas < ob.mass();
}

void Hexagon::draw() {
    cout << name << endl;
    cout << "Cordinates: " << endl;
    cout << "V1: " << "("<< v1.x << ", " << v1.y << ")" << endl;
    cout << "V2: " << "("<< v2.x << ", " << v2.y << ")" << endl;
    cout << "V3: " << "("<< v3.x << ", " << v3.y << ")" << endl;
    cout << "V4: " << "("<< v4.x << ", " << v4.y << ")" << endl;
    cout << "V5: " << "("<< v5.x << ", " << v5.y << ")" << endl;
    cout << "V6: " << "("<< v6.x << ", " << v6.y << ")" << endl;
    cout << "Center: " << "(" << position().x << ", " << position().y << ")" << endl;
    cout << "Square: " << square() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

void Hexagon::initFromDialog() {
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
    cout << "x of V3 = ";
    cin >> v3.x;
    cout << "y of V3 = ";
    cin >> v3.y;
    cout << "x of V4 = ";
    cin >> v4.x;
    cout << "y of V4 = ";
    cin >> v4.y;
    cout << "x of V5 = ";
    cin >> v5.x;
    cout << "y of V5 = ";
    cin >> v5.y;
    cout << "x of V6 = ";
    cin >> v6.x;
    cout << "y of V6 = ";
    cin >> v6.y;
}

const char *Hexagon::classname() {
    return name;
}

unsigned int Hexagon::size() {
    return sizeof(*this);
}