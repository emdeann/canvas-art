#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(const Point& _topLeft, const Point& _bottomRight) {
    Point _topRight(_bottomRight.getX(), _topLeft.getY());
    Point _bottomLeft(_topLeft.getX(), _bottomRight.getY());

    Line topLine(_topLeft, _topRight);
    lines.push_back(topLine);
    Line rightLine(_topRight, _bottomRight);
    lines.push_back(rightLine);
    Line bottomLine(_bottomLeft, _bottomRight);
    lines.push_back(bottomLine);
    Line leftLine(_topLeft, _bottomLeft);
    lines.push_back(leftLine);

    for (Line& l : lines) {
        vector<Point> linePoints = l.getPoints();
        points.insert(points.end(), linePoints.begin(), linePoints.end());
    }
    
    this -> width = abs(_topLeft.getX() - _bottomRight.getX()) + 1;
    this -> height = abs(_topLeft.getY() - _bottomRight.getY()) + 1;
    
}

const vector<Point> Rectangle::getPoints() const {
    return points;
}

float Rectangle::getArea() const {
    return width * height;
}