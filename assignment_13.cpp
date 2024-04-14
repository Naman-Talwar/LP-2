#include <iostream>
#include <string>
using namespace std;

class menuItem {
protected:
    string name;
    int price;
public:
    menuItem(const string& name, int price) : name(name), price(price) {}

    virtual int getPrice() {
        return price;
    }

    virtual void display() {
        cout << name << " : " << price << " rupees" << endl;
    }
};

class specialMenuItem : public menuItem {
private:
    string category;
public:
    specialMenuItem(const string& name, int price, const string& category) : menuItem(name, price), category(category) {}

    void display() {
        cout << name << " : " << price << " rupees (" << category << ")" << endl;
    }
};

class customerOrder {
private:
    string customerName;
    menuItem* items[10];
    int itemCount;
public:
    customerOrder(const string& customerName) : customerName(customerName), itemCount(0) {}

    void addItem(menuItem* item) {
        if (itemCount < 10) {
            items[itemCount++] = item;
        } else {
            cout << "Maximum items reached for this order." << endl;
        }
    }

    int getTotalPrice() {
        int total = 0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->getPrice();
        }
        return total;
    }

    void display() {
        cout << "Customer Name : " << customerName << endl;
        cout << "Ordered Items :" << endl;
        for (int i = 0; i < itemCount; ++i) {
            items[i]->display();
        }
        cout << "Total Price : " << getTotalPrice() << " rupees" << endl;
    }
};

class Bill {
private:
    customerOrder* orders[10];
    int orderCount;
public:
    Bill() : orderCount(0) {}

    void addOrder(customerOrder* order) {
        if (orderCount < 10) {
            orders[orderCount++] = order;
        } else {
            cout << "Maximum orders reached for this bill." << endl;
        }
    }

    int calculateTotalBill() {
        int total = 0;
        for (int i = 0; i < orderCount; ++i) {
            total += orders[i]->getTotalPrice();
        }
        return total;
    }

    void display() {
        cout << "--------------- Bill ---------------" << endl;
        for (int i = 0; i < orderCount; ++i) {
            orders[i]->display();
            cout << "------------------------------------" << endl;
        }
        cout << "Total Bill : " << calculateTotalBill() << " rupees" << endl;
    }
};

int main() {
    menuItem obj1("Burger", 50);
    menuItem obj2("Pizza", 100);
    specialMenuItem obj3("Coca Cola", 40, "Drinks");
    specialMenuItem obj4("Ice Cream", 80, "Desserts");

    customerOrder obj5("Naman Talwar");
    obj5.addItem(&obj1);
    obj5.addItem(&obj3);

    customerOrder obj6("Navneet Garg");
    obj6.addItem(&obj2);
    obj6.addItem(&obj4);

    Bill obj7;
    obj7.addOrder(&obj5);
    obj7.addOrder(&obj6);

    obj7.display();

    return 0;
}
