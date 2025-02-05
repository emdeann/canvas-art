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