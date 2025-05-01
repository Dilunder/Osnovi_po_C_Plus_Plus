#include "triangle.h"
#include <cmath>

vector::vector(double x, double y):x(x), y(y){}

double vector::get_x() const{
    return x;
}
double vector::get_y() const{
    return y;
}

double vector::distance(const vector &to) const{
    return sqrt((x - to.get_x()) * (x - to.get_x()) + (y - to.get_y()) * (y - to.get_y()));
}

triangle::triangle(const vector &a, const vector &b, const vector &c):a(a), b(b), c(c){}

vector triangle::get_a() const{
    return a;
}
vector triangle::get_b() const{
    return b;
}
vector triangle::get_c() const{
    return c;
}
double triangle::square() const{
    double ab = a.distance(b);
    double ac = a.distance(c);
    double bc = b.distance(c);
    double P = (ab+ac+bc) / 2;
    return sqrt(P * (P - ab) * (P - ac) * (P - bc));
}
bool triangle::operator==(const triangle& ro) const{
    return square() == ro.square();
}
bool triangle::operator!=(const triangle& ro) const{
    return square() != ro.square();
}
bool triangle::operator<(const triangle& ro) const{
    return square() < ro.square();
}
bool triangle::operator>(const triangle& ro) const{
    return square() > ro.square();
}
bool triangle::operator<=(const triangle& ro) const{
    return square() <= ro.square();
}
bool triangle::operator>=(const triangle& ro) const{
    return square() >= ro.square();
}
triangle triangle::operator+(const vector& ro) const{
    vector a1(get_a().get_x() + ro.get_x(), get_a().get_y() + ro.get_y());
    vector a2(get_b().get_x() + ro.get_x(), get_b().get_y() + ro.get_y());
    vector a3(get_c().get_x() + ro.get_x(), get_c().get_y() + ro.get_y());
    triangle extra(a1, a2, a3);
    return extra;
}