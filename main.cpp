#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
    int id = 0;
    double balance = 15.00;
    static inline int counter = 0;

public:
    string name;
    bool membership;

    Account (string n, bool m) {
        name = n;
        membership = m;
        id = counter++;
    }

    void showAccount() {
        cout << "============================" << endl;
        cout << "Account:" << " " << name << endl;
        cout << "Membership status:" << " " << (membership ? "Active" : "Inactive") << endl;
        cout << "Balance:" << balance << endl;
        cout << "Id:" << id << endl;
    }
};


class Book {
private:
    string title;
    string author;
    double price;
    bool status;

public:
    Book (string t, string a, double b, bool s) {
        title = t;
        author = a;
        price = b;
        status = s;

    }

    string getTitle () const {
        return title;
    }

    void showBook () {
        cout << "---------------------------" << endl;
        cout << "Title:" << " " << title << endl;
        cout << "Author:" << " " << author << endl;
        cout << "Price:" << " " << price << endl;
        cout << "Status: " << (status ? "Borrowed" : "Free") << endl;
        cout << "---------------------------" << endl;
    }
    void showStatus () {
        cout << "Status of " << title << ":" << " " << (status ? "Borrowed" : "Free") << endl;
    }

    void borrow(Account& a) {
        cout << a.name << " has borrowed" << " " << title << endl;
        status = true;
    }

    void returnBook(Account& a) {
        cout << a.name << " has returned" << " " << title << endl;
        status = false;
    }

};

class Library {
private:
    vector <Book> books;

public:
    void addBook (Book& a) {
        books.push_back(a);
    }

    void showBooks () {
        for (auto& book: books) {
            cout << book.getTitle() << endl;
        }
    }
};

int main () {

    Library library;
    Account a ("John" , false);
    Account b ("Bonny" , false);
    Book book1 ("Norwegian Wood", "Murakami", 10.99, false);
    Book book2 ("Your Lie In April", "Arakawa", 10.99, false);

}