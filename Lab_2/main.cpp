#include <iostream>
#include "Vector3.h"

int main() {
    float x, y, z;
    cin >> x >> y >> z;
    vector3 v1(x, y, z);
    cin >> x >> y >> z;
    vector3 v2(x, y, z);
    cout << "Summa vectorov: " << v2 + v1 << endl;
    cout << "Raznost vectorov: " << v2 - v1 << endl;
    cout << "Dlina pervogo vectora: " << v1.magnitude() << endl;
    cout << "Dlina vtorogo vectora: " << v2.magnitude() << endl;
    cout << "Ugol mejdu vectorami: " << v1.angle(v2) << endl;
    return 0;
}
