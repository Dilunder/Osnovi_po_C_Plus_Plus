#ifndef LAB_2_VECTOR3_H
#define LAB_2_VECTOR3_H

#include <iostream>

using namespace std;

class vector3{
private:
    float x;
    float y;
    float z;
public:
    vector3();
    vector3(const vector3& v);
    vector3(float x, float y, float z);
    vector3& operator= (const vector3& v);
    vector3 operator+ (const vector3& v) const;
    vector3 operator- (const vector3& v) const;
    float get_x() const;
    float get_y() const;
    float get_z() const;
    float magnitude() const;
    float angle(const vector3& v) const;
};

std::ostream& operator<<(std::ostream& out, const vector3& v);

#endif
