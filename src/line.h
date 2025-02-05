#pragma once

#include "point.h"
#include "shape.h"

#include <vector>

class Line : public AbstractShape {
private:
    Point p1;
    Point p2;
public:
    Line(const Point& _pt1, const Point& _pt2);
    const std::vector<Point> getPoints() const;
    float getArea() const;
};
