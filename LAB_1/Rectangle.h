#pragma once
#include "Point.h"

class Rectangle {
    Point* A;
    Point* B;
    Point* C;

public:
    Rectangle();
    Rectangle(double x1, double y1,
        double x2, double y2,
        double x3, double y3);
    Rectangle(const Rectangle& other);
    ~Rectangle();

    Rectangle& operator=(const Rectangle& other);

    Rectangle operator-() const;
    Rectangle operator+(const Rectangle& other) const;

    double Area() const;
    double Perimeter() const;
    void   Move(double dx, double dy);

    Point GetA() const { return *A; }
    Point GetB() const { return *B; }
    Point GetC() const { return *C; }
    Point GetD() const;

    void Print() const;
};