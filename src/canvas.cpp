#include "canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height, std::string author) : AbstractGrid(width, height) {
    this->author = author;
    this->shapes = vector<AbstractShape>();
}

void Canvas::addShape(const shared_ptr<AbstractShape> shape) {
    shapes.push_back(*shape);
}

void Canvas::draw() const {
    AbstractGrid::draw();
    cout << "Author: " << author << endl;
}

float Canvas::getPaintNeeded() const {
    float paintNeeded = 0;
    for (AbstractShape s : shapes) {
        paintNeeded += s.getArea();
    }

    return paintNeeded;
}