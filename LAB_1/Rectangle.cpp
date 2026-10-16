#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() {
    A = new Point{ 0, 0 };
    B = new Point{ 1, 0 };
    C = new Point{ 1, 1 };
}

Rectangle::Rectangle(double x1, double y1,
    double x2, double y2,
    double x3, double y3) {
    A = new Point{ x1, y1 };
    B = new Point{ x2, y2 };
    C = new Point{ x3, y3 };
}

Rectangle::Rectangle(const Rectangle& other) {
    A = new Point{ other.A->x, other.A->y };
    B = new Point{ other.B->x, other.B->y };
    C = new Point{ other.C->x, other.C->y };
}

Rectangle::~Rectangle() {
    delete A;
    delete B;
    delete C;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        delete A;
        delete B;
        delete C;

        A = new Point{ other.A->x, other.A->y };
        B = new Point{ other.B->x, other.B->y };
        C = new Point{ other.C->x, other.C->y };
    }
    return *this;
}

Point Rectangle::GetD() const {
    Point D;
    D.x = A->x + C->x - B->x;
    D.y = A->y + C->y - B->y;
    return D;
}

double Rectangle::Area() const {
    double ab = std::sqrt((A->x - B->x) * (A->x - B->x) +
        (A->y - B->y) * (A->y - B->y));
    double cb = std::sqrt((C->x - B->x) * (C->x - B->x) +
        (C->y - B->y) * (C->y - B->y));
    return ab * cb;
}

double Rectangle::Perimeter() const {
    double ab = std::sqrt((A->x - B->x) * (A->x - B->x) +
        (A->y - B->y) * (A->y - B->y));
    double cb = std::sqrt((C->x - B->x) * (C->x - B->x) +
        (C->y - B->y) * (C->y - B->y));
    return 2.0 * (ab + cb);
}

void Rectangle::Move(double dx, double dy) {
    A->x += dx; A->y += dy;
    B->x += dx; B->y += dy;
    C->x += dx; C->y += dy;
}

Rectangle Rectangle::operator-() const {
    Rectangle r(-A->x, -A->y,
        -B->x, -B->y,
        -C->x, -C->y);
    return r;
}

Rectangle Rectangle::operator+(const Rectangle& other) const {
    Point p[8] = { *A, *B, *C, GetD(),
                   *other.A, *other.B, *other.C, other.GetD() };

    double minX = p[0].x, maxX = p[0].x;
    double minY = p[0].y, maxY = p[0].y;

    for (int i = 1; i < 8; i++) {
        if (p[i].x < minX) minX = p[i].x;
        if (p[i].x > maxX) maxX = p[i].x;
        if (p[i].y < minY) minY = p[i].y;
        if (p[i].y > maxY) maxY = p[i].y;
    }

    Rectangle r(minX, minY,
        maxX, minY,
        maxX, maxY);
    return r;
}

void Rectangle::Print() const {
    Point D = GetD();
    std::cout << "A(" << A->x << ", " << A->y << ")\n";
    std::cout << "B(" << B->x << ", " << B->y << ")\n";
    std::cout << "C(" << C->x << ", " << C->y << ")\n";
    std::cout << "D(" << D.x << ", " << D.y << ")\n";
}