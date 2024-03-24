#include <iostream>
using namespace std;

int sum_of_series(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (i * (i + 1)) / 2;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        return 1;
    }

    int result = sum_of_series(n);
    cout << "Sum of the series of " << n << " : " << result << endl;

    return 0;
}
