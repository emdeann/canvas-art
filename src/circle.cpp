#include "circle.h"
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

Circle::Circle(const Point& _center, int _radius) : 
    center(Point(_center.getX(), _center.getY())), radius(_radius) {
}

float Circle::getArea() const {
    return M_PI * radius * radius;
}

const std::vector<Point> Circle::getPoints() const {
    int x0 = center.getX();
    int y0 = center.getY();
    
    int x = 0;
    int y = radius;
    int error = 1 - radius;

    vector<Point> points;

    do {
        points.push_back(Point(x0 + x, y0 + y));
        points.push_back(Point(x0 + y, y0 + x));
        points.push_back(Point(x0 - y, y0 + x));
        points.push_back(Point(x0 - x, y0 + y));
        points.push_back(Point(x0 - x, y0 - y));
        points.push_back(Point(x0 - y, y0 - x));
        points.push_back(Point(x0 + y, y0 - x));
        points.push_back(Point(x0 + x, y0 - y));

        if (error < 0) {
            error += (2 * x) + 1;
        } else {
            y--;
            error += (2 * x) - (2 * y) + 1;
        }
        x++;
    } while (y > x);

    return points;
}