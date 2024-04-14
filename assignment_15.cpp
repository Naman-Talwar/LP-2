#include <iostream>
using namespace std;

class classB;

class classA {
private:
    int a;
public:
    classA(int val) : a(val) {}

    friend int sum(classA& obj1, classB& obj2);
};

class classB {
private:
    int b;
public:
    classB(int val) : b(val) {}

    friend int sum(classA& obj1, classB& obj2);
};

int sum(classA& obj1, classB& obj2) {
    return obj1.a + obj2.b;
}

int main() {
    classA obj1(5);
    classB obj2(10);

    cout << "Sum of obj1(5) and obj2(10) : " << sum(obj1, obj2) << endl;

    return 0;
}
