/*
 * Copyright (C) 2025 YANG Rui <yangrui1028@gmail.com>
 *
 * This file is part of DesignPatternsCPP.
 *
 * Licensed under the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <memory>

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::shared_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}
    std::shared_ptr<Shape> clone() const override {
        return std::make_shared<Circle>(*this);
    }
    void draw() const override {
        std::cout << "draw a circle, which radius is " << radius_ << std::endl;
    }
private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    std::shared_ptr<Shape> clone() const override {
        return std::make_shared<Rectangle>(*this);
    }
    void draw() const override {
        std::cout << "draw a rectangle, width is " << width_ << ", height is " << height_ << std::endl;
    }
private:
    double width_, height_;
};

int main() {
    std::shared_ptr<Shape> circlePrototype = std::make_shared<Circle>(10.0);
    std::shared_ptr<Shape> rectanglePrototype = std::make_shared<Rectangle>(20.0, 15.0);

    auto clonedCircle = circlePrototype->clone();
    auto clonedRectangle = rectanglePrototype->clone();

    clonedCircle->draw();
    clonedRectangle->draw();

    return 0;
}
