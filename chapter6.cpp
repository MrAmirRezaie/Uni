#include <iostream>
using namespace std;

class Saving 
{
private:
    double savebal;
    static double rate;

public:
    Saving(double bal) : savebal(bal) {}

    void calculate() 
    {
        savebal += (savebal / 12) * rate;
    }

    double getBalance() const 
    {
        return savebal;
    }

    static void setRate(double r) 
    {
        rate = r;
    }
};

double Saving::rate = 0;

int main() 
{
    double bal1, bal2, rate;

    cout << "Enter balance for saving account 1: ";
    cin >> bal1;

    cout << "Enter balance for saving account 2: ";
    cin >> bal2;

    cout << "Enter monthly interest rate: ";
    cin >> rate;

    Saving::setRate(rate);

    Saving s1(bal1);
    Saving s2(bal2);

    s1.calculate();
    s2.calculate();

    cout << "New balance for saving account 1: " << s1.getBalance() << endl;
    cout << "New balance for saving account 2: " << s2.getBalance() << endl;

    return 0;
}