#include <iostream>
#include <string>
using namespace std;

class Computer 
{
protected:
    double price;
    double weight;
    string brand;
    string model;

public:
    Computer(double p, double w, string b, string m) : price(p), weight(w), brand(b), model(m) {}
    virtual ~Computer() {}
};

class Laptop : public Computer 
{
private:
    double batteryLife;

public:
    Laptop(double p, double w, string b, string m, double bl) : Computer(p, w, b, m), batteryLife(bl) {}
    ~Laptop() {}

    void printLaptop() const 
    {
        cout << "Laptop - Brand: " << brand << ", Model: " << model << ", Price: " << price 
             << ", Weight: " << weight << ", Battery Life: " << batteryLife << " hours" << endl;
    }
};

class Desktop : public Computer 
{
private:
    string monitorType;

public:
    Desktop(double p, double w, string b, string m, string mt) : Computer(p, w, b, m), monitorType(mt) {}
    ~Desktop() {}

    void printDesktop() const 
    {
        cout << "Desktop - Brand: " << brand << ", Model: " << model << ", Price: " << price 
             << ", Weight: " << weight << ", Monitor Type: " << monitorType << endl;
    }
};

int main() 
{
    double price, weight, batteryLife;
    string brand, model, monitorType;

    cout << "Enter price, weight, brand, model, battery life for the laptop: ";
    cin >> price >> weight >> brand >> model >> batteryLife;
    Laptop laptop(price, weight, brand, model, batteryLife);
    laptop.printLaptop();

    cout << "Enter price, weight, brand, model, monitor type for the desktop: ";
    cin >> price >> weight >> brand >> model >> monitorType;
    Desktop desktop(price, weight, brand, model, monitorType);
    desktop.printDesktop();

    return 0;
}