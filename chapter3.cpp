#include <iostream>
#include <cmath>
using namespace std;

class Point 
{
private:
    double x, y;

public:
    Point() : x(0), y(0) {}
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}
    Point(const Point &p) : x(p.x), y(p.y) {}

    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    double getX() const { return x; }
    double getY() const { return y; }

    double distToOrigin() const 
    {
        return sqrt(x * x + y * y);
    }

    double distToAnotherPoint(const Point &p) const 
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

    virtual void Print() const 
    {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

class Circle : public Point 
{
private:
    double radius;

public:
    Circle(double xVal, double yVal, double r) : Point(xVal, yVal), radius(r) {}

    double getArea() const 
    {
        return M_PI * radius * radius;
    }

    double getCircumference() const 
    {
        return 2 * M_PI * radius;
    }

    void Print() const override 
    {
        cout << "Circle Center (" << getX() << ", " << getY() << ") with Radius: " << radius << endl;
    }
};

int main() 
{
    double x, y, r;

    cout << "Enter x and y for the circle center: ";
    cin >> x >> y;

    cout << "Enter radius of the circle: ";
    cin >> r;

    Circle c(x, y, r);
    c.Print();

    cout << "Area: " << c.getArea() << endl;

    cout << "Circumference: " << c.getCircumference() << endl;

    return 0;
}