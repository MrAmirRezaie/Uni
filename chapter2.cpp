#include <iostream>
#include <cmath>
using namespace std;

class Point {
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

    double distToOrigin() const {
        return sqrt(x * x + y * y);
    }

    double distToAnotherPoint(const Point &p) const {
        return sqrt((x - p.x) * (x - p.y) + (y - p.y) * (y - p.y));
    }

    void Print() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    double x1, y1, x2, y2;
    cout << "Enter x and y for the first point: ";
    cin >> x1 >> y1;
    cout << "Enter x and y for the second point: ";
    cin >> x2 >> y2;

    Point p1(x1, y1);
    Point p2(x2, y2);

    cout << "Distance between the two points: " << p1.distToAnotherPoint(p2) << endl;

    return 0;
}
