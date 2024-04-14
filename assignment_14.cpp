#include <iostream>
#include <string>
using namespace std;

class stringOperation {
private:
    string* strPtr;
public:
    stringOperation(const string& str) {
        strPtr = new string(str);
    }

    ~stringOperation() {
        delete strPtr;
    }

    int countWords() {
        int count = 0;
        bool inWord = 0;

        for (int i = 0; (*strPtr)[i] != '\0'; i++) {
            char c = (*strPtr)[i];
            if (isalpha(c)) {
                count += !inWord;
                inWord = 1;
            } else {
                inWord = 0;
            }
        }
        return count;
    }
};

int main() {
    stringOperation obj("Hello, I am Naman Talwar");

    cout << "Total words in (Hello, I am Naman Talwar) : " << obj.countWords() << endl;

    return 0;
}
