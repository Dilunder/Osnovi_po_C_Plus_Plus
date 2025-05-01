#ifndef LAB_4_SIX_EDGES_H
#define LAB_4_SIX_EDGES_H

#include "virtual.h"

class Hexagon : public IFigue {
private:
    double mas;
    CVector2D v1, v2, v3, v4, v5, v6;
    const char *name = "hexagon";
public:
    Hexagon();
    virtual ~Hexagon();
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