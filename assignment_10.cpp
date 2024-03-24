#include <iostream>
#include <string>
using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    int year;
};

int main() {
    Book library[5];

    library[0] = {"978-0571313255", "The Waste Land", "T.S. Eliot", 1922};
    library[1] = {"978-0375753808", "Selected Poems", "W.H. Auden", 1979};
    library[2] = {"978-0679722649", "The Collected Poems", "Langston Hughes", 1994};
    library[3] = {"978-0061583246", "The Essential Rumi", "Jalal ad-Din Muhammad Rumi", 1995};
    library[4] = {"978-0679728856", "The Horror Poems", "Wallace Stevens", 1990};

    cout << "Enter the ISBN of the book you are looking for: ";
    string isbn;
    cin >> isbn;

    bool found = 0;
    for (int i = 0; i < 5; ++i) {
        if (library[i].isbn == isbn) {
            cout << "Book Found!" << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Year: " << library[i].year << endl;
            found = 1;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, the book with ISBN " << isbn << " is not available in the library." << endl;
    }

    return 0;
}
