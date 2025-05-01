#include "Vector3.h"
#include <iostream>
#include <cmath>

vector3::vector3()
    : x(0), y(0), z(0)
{}

vector3::vector3(const vector3& v)
    : x(v.x), y(v.y), z(v.z)
{}

vector3::vector3(float x, float y, float z)
    : x(x), y(y), z(z)
{}

vector3& vector3::operator= (const vector3& v){
    if(&v == this) return *this;
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

vector3 vector3::operator+ (const vector3& v) const{
    return vector3(x + v.x, y + v.y, z + v.z);
}

vector3 vector3::operator- (const vector3& v) const{
    return vector3(x - v.x, y - v.y, z - v.z);
}

float vector3::get_x() const{
    return x;
}

float vector3::get_y() const{
    return y;
}

float vector3::get_z() const{
    return z;
}

float vector3::magnitude() const{
    return(sqrt(x * x + y * y + z * z));
}

float vector3::angle(const vector3& v) const{
    return(acos((x * v.x + y * v.y + z * v.z)/(magnitude() * v.magnitude())));
}

std::ostream& operator<<(std::ostream& out, const vector3& v){
    out << '(' << v.get_x() << ", " << v.get_y() << ", " << v.get_z() << ')';
}
