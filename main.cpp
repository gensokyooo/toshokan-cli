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

    double getBalance () const {
        return balance;
    }

};

class AccManager {

private:
    vector <Account> accounts;

public:
    string name;
    bool membership;

    void createAccount () {
        cout << "Enter name:" << " ";  cin >> name;
        cout << endl;
        membership = true;
        Account a (name, membership);
        cout << endl;
        a.showAccount();

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

    cout << "=========================" << endl;
    cout << "Welcome to Toshokan" << endl;
    cout << "=========================" << endl;

    int x;
    cout << "What would you like to do today?";
    cout << "\n 1. Create an account \n 2. Sell a book \n 3. Buy a book \n 4. View books " << endl;
    cout << "-------------------------" << endl;

    cout << "Select an option: "; cin >> x;

    AccManager accmanager;

    while (x != 0) {
        switch (x) {
            case 1: accmanager.createAccount();
                break;
        }
    cout << "Select an option: "; cin >> x;
    }


}