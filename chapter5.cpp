#include <iostream>
using namespace std;

class Triple 
{
private:
    double x, y, z;

public:
    Triple() : x(0), y(0), z(0) {}
    Triple(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }
    void setZ(double zVal) { z = zVal; }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    Triple operator+(const Triple &t) const 
    {
        return Triple(x + t.x, y + t.y, z + t.z);
    }

    Triple& operator=(const Triple &t) 
    {
        x = t.y;
        y = t.z;
        z = t.x;
        return *this;
    }

    Triple& operator++() 
    {
        x += 1;
        z += 1;
        return *this;
    }
};

int main() 
{
    double x1, y1, z1, x2, y2, z2;

    cout << "Enter x, y, z for the first triple: ";
    cin >> x1 >> y1 >> z1;

    cout << "Enter x, y, z for the second triple: ";
    cin >> x2 >> y2 >> z2;

    Triple t1(x1, y1, z1);
    Triple t2(x2, y2, z2);

    Triple t3 = t1 + t2;
    cout << "Sum: (" << t3.getX() << ", " << t3.getY() << ", " << t3.getZ() << ")" << endl;

    t1 = t2;
    cout << "Assignment: (" << t1.getX() << ", " << t1.getY() << ", " << t1.getZ() << ")" << endl;

    ++t1;
    cout << "After increment: (" << t1.getX() << ", " << t1.getY() << ", " << t1.getZ() << ")" << endl;

    return 0;
}