#pragma once

#include "line.h"
#include "point.h"
#include "shape.h"

#include <vector>

using namespace std;

class Rectangle : public AbstractShape {
private:
    vector<Line> lines;
    vector<Point> points;
    int width;
    int height;
public:
    Rectangle(const Point& _topLeft, const Point& _bottomRight);
    const vector<Point> getPoints() const;
    float getArea() const;
};
