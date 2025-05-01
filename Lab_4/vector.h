#ifndef LAB_4_VECTOR_H
#define LAB_4_VECTOR_H

#include "virtual.h"

class Vector : public IFigue {
private:
    double mas;
    CVector2D v1, v2;
    const char *name = "Vector";
public:
    Vector();
    virtual ~Vector();
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    bool operator==(const IPhysObject &ob) const override;
    bool operator<(const IPhysObject &ob) const override;
    void draw() override;
    void initFromDialog() override;
    const char *classname() override;
    unsigned int size() override;
};

#endif
