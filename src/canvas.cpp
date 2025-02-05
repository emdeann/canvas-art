#include "canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height, std::string author) : AbstractGrid(width, height) {
    this->author = author;
    this->shapes = vector<shared_ptr<AbstractShape> >();
}

void Canvas::addShape(const shared_ptr<AbstractShape> shape) {
    shapes.push_back(shape);
}

void Canvas::draw() const {
    AbstractGrid::draw();
    cout << "Author: " << author << endl;
}

float Canvas::getPaintNeeded() const {
    float paintNeeded = 0;
    for (shared_ptr<AbstractShape> s : shapes) {
        paintNeeded += s->getArea();
    }

    return paintNeeded;
}

const vector<Point> Canvas::getPoints() const {
    vector<Point> points;
    for (shared_ptr<AbstractShape> s : shapes) {
        vector<Point> shapePoints = s->getPoints();
        points.insert(points.end(), shapePoints.begin(), shapePoints.end());
    }

    return points;
}