#include <iostream>
#include <cmath>
using namespace std;

class Shape 
{
public:
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape 
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    ~Circle() {}

    double Perimeter() const override 
    {
        return 2 * M_PI * radius;
    }

    double Area() const override 
    {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape 
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    ~Rectangle() {}

    double Perimeter() const override 
    {
        return 2 * (width + height);
    }

    double Area() const override 
    {
        return width * height;
    }
};

int main() 
{
    double radius, width, height;
    
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    Shape* circle = new Circle(radius);

    cout << "Circle Perimeter: " << circle->Perimeter() << endl;
    cout << "Circle Area: " << circle->Area() << endl;

    cout << "Enter the width and height of the rectangle: ";
    cin >> width >> height;
    Shape* rectangle = new Rectangle(width, height);

    cout << "Rectangle Perimeter: " << rectangle->Perimeter() << endl;
    cout << "Rectangle Area: " << rectangle->Area() << endl;

    delete circle;
    delete rectangle;

    return 0;
}