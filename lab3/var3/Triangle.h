#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

class Triangle {
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

    double area() const;
    void translate(double dx, double dy);

    bool operator==(const Triangle& other) const;
    bool operator!=(const Triangle& other) const;
    bool operator<(const Triangle& other) const;
    bool operator>(const Triangle& other) const;

    Triangle& operator+=(const std::pair<double, double>& vector);

private:
    double m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;

    double distance(double x1, double y1, double x2, double y2) const;
};

#endif // TRIANGLE_H
