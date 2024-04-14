#include <iostream>
using namespace std;

class largerUnit;

class smallUnit {
private:
    float inches;
public:
    smallUnit(float inches) : inches(inches) {}

    operator largerUnit();

    float getInches() {
        return inches;
    }
};

class largerUnit {
private:
    float feet;
public:
    largerUnit(float feet) : feet(feet) {}

    float getFeet() {
        return feet;
    }

    void display() {
        cout << "Measurement in feet : " << feet << endl;
        cout << "Measurement in inches : " << feet * 12.0 << endl;
    }
};

smallUnit::operator largerUnit() {
    return largerUnit(inches / 12.0);
}

int main() {
    smallUnit obj1(36.0);
    largerUnit obj2 = obj1;

    obj2.display();

    return 0;
}
