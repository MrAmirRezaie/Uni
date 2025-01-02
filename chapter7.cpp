#include <iostream>
using namespace std;

class Complex 
{
private:
    double real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    double getReal() const { return real; }
    double getImag() const { return imag; }

    void print() const 
    {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator+(const Complex &c) const 
    {
        return Complex(real + c.real, imag + c.imag);
    }

    bool operator==(const Complex &c) const 
    {
        return (real == c.real && imag == c.imag);
    }
};

int main() 
{
    double r1, i1, r2, i2;
    cout << "Enter real and imaginary parts for the first complex number: ";
    cin >> r1 >> i1;
    cout << "Enter real and imaginary parts for the second complex number: ";
    cin >> r2 >> i2;

    Complex c1(r1, i1);
    Complex c2(r2, i2);

    Complex c3 = c1 + c2;
    cout << "Sum: ";
    c3.print();

    if (c1 == c2)
        cout << "The complex numbers are equal" << endl;
    else
        cout << "The complex numbers are not equal" << endl;

    return 0;
}