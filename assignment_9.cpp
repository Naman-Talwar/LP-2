#include <iostream>
using namespace std;

class Operations {
private:
    float height;
    float weight;
public:
    Operations() {}
    Operations(float h, float w) : height(h), weight(w) {}

    void addition() {
        cout << "Addition : " << height + weight << endl; 
    }
    void substraction() {
        cout << "Substraction : " << height - weight << endl;
    }

    friend Operations operator + (Operations obj, Operations obj1);
    friend Operations operator - (Operations obj, Operations obj1);
};

Operations operator + (Operations obj, Operations obj1) {
    float mainHeight = obj.height + obj1.height;
    float mainWeight = obj.weight + obj1.weight;
    return Operations(mainHeight, mainWeight);
}
Operations operator - (Operations obj, Operations obj1) {
    float mainHeight = obj.height - obj1.height;
    float mainWeight = obj.weight - obj1.weight;
    return Operations(mainHeight, mainWeight);
}

int main() {
    Operations a(165.2, 60.5);
    Operations b(155.2, 55.5);
    Operations c;
    c = a + b;
    c.addition();
    c = a - b;
    c.substraction();

    return 0;
}

