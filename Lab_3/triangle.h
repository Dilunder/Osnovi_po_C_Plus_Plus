#ifndef LAB_3_TRIANGLE_H
#define LAB_3_TRIANGLE_H

class vector{
private:
    double x, y;
public:
    vector(double x, double y);
    double get_x() const;
    double get_y() const;
    double distance(const vector &to) const;
};

class triangle{
private:
    vector a;
    vector b;
    vector c;
public:
    triangle(const vector &a, const vector &b, const vector &c);
    vector get_a() const;
    vector get_b() const;
    vector get_c() const;
    double square() const;
    bool operator==(const triangle& ro) const;
    bool operator!=(const triangle& ro) const;
    bool operator<(const triangle& ro) const;
    bool operator>(const triangle& ro) const;
    bool operator<=(const triangle& ro) const;
    bool operator>=(const triangle& ro) const;
    triangle operator+(const vector& ro) const;
};

#endif
