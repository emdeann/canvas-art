#include "line.h"

using namespace std;

Line::Line(const Point& _pt1, const Point& _pt2) : p1(_pt1.getX(), _pt1.getY()), 
    p2(_pt2.getX(), _pt2.getY()) {
}

float Line::getArea() const {
    return 0; // lines have no area
}

const vector<Point> Line::getPoints() const {
    int x1 = p1.getX();
    int y1 = p1.getY();
    int x2 = p2.getX();
    int y2 = p2.getY();

    vector<Point> points;

    int dx =  abs (x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs (y2 - y1), sy = y1 < y2 ? 1 : -1; 
    int error = dx + dy;
    int e2;

    while (true) {
      
      points.push_back(Point(x1, x2));
      
      if (x1 == x2 && y1 == y2) {
          break;
      }
      e2 = 2 * error;
      if (e2 >= dy) { error += dy; x1 += sx; }
      if (e2 <= dx) { error += dx; y1 += sy; }
    }

    return points;
}