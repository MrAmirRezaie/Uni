#include <iostream>
using namespace std;

class POINT 
{
private:
    double x, y;

public:
    POINT() : x(0), y(0) {}

    POINT(double x_value, double y_value) : x(x_value), y(y_value) {}

    POINT(const POINT& p) : x(p.x), y(p.y) {}

    void setX(double x_value) 
    {
        x = x_value;
    }

    void setY(double y_value) 
    {
        y = y_value;
    }

    double getX() const 
    {
        return x;
    }

    double getY() const 
    {
        return y;
    }

    void print() const 
    {
        cout << "POINT(" << x << ", " << y << ")" << endl;
    }

    bool operator==(const POINT& p) const 
    {
        return (x == p.x && y == p.y);
    }

    friend bool operator!=(const POINT& p1, const POINT& p2) 
    {
        return !(p1 == p2);
    }
};

int main() 
{
    double x1, y1, x2, y2;

    cout << "Enter coordinates for point 1 (x1 y1): ";
    cin >> x1 >> y1;
    POINT p1(x1, y1);

    cout << "Enter coordinates for point 2 (x2 y2): ";
    cin >> x2 >> y2;
    POINT p2(x2, y2);

    cout << "Point 1: ";
    p1.print();

    cout << "Point 2: ";
    p2.print();

    if (p1 == p2) 
    {
        cout << "Point 1 and Point 2 are equal." << endl;
    }
    else 
    {
        cout << "Point 1 and Point 2 are not equal." << endl;
    }

    return 0;
}