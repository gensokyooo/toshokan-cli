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

    void showAccount() const {
        cout << "============================" << endl;
        cout << "Account:" << " " << name << endl;
        cout << "Membership status:" << " " << (membership ? "Active" : "Inactive") << endl;
        cout << "Balance:" << balance << endl;
        cout << "Id:" << id << endl;
    }

    double getBalance () {
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

    vector <Account>& getAccounts () {
        accounts;
    }

    void showAllAccounts () {
        for (const auto& acc: accounts) {
            acc.showAccount();
        }
    }

    int selectAccount() {
        cout << "Select the account you'd like to use" << endl;
        showAllAccounts();
        int x;
        cout << "Select:"; cin >> x; cout << endl;
        return x;
    }

};

class Book {
private:
    string title;
    string author;
    double price;
    bool status;
    int id = 0;
    static inline int counter = 0;

public:
    Book (string t, string a, double b, bool s) {
        title = t;
        author = a;
        price = b;
        status = s;
        id = counter++;

    }

    string getTitle () const {
        return title;
    }

    int getId() const {
        return id;
    }

    double getPrice() {
        return price;
    }


    void showBook () {
        cout << "---------------------------" << endl;
        cout << "Title:" << " " << title << endl;
        cout << "Author:" << " " << author << endl;
        cout << "Price:" << " " << price << endl;
        cout << "Status: " << (status ? "Borrowed" : "Free") << endl;
        cout << "Id: " << id << endl;
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

    void showAllBooks () {
        for (auto& book: books) {
            book.showBook();
        }
    }

    AccManager m;
    void buyBook() {

        int acc_id = m.selectAccount();
        cout << "Which book would you like to buy?" << endl;
        showAllBooks();
        int x;
        cout << "Select ID: "; cin >> x;
        cout << "You've bought: " << books[x].getTitle() << endl;
        // We have to do: acc balance - book price
        // = new account balance
        m.getAccounts()[acc_id].getBalance() -= books[x].getPrice();
        cout << "Your new balance is:"; m.getAccounts()[acc_id].getBalance() - books[x].getPrice();

    }
};

int main () {

    Library library;
    Book book1 ("Norwegian Wood" , "Murakami", 9.99, false);
    library.addBook(book1);

    cout << "=========================" << endl;
    cout << "Welcome to Toshokan" << endl;
    cout << "=========================" << endl;

    int x;
    cout << "What would you like to do today?";
    cout << "\n 1. Create an account \n 2. Buy a book \n 3. Go to owned books \n 4. View books catalog \n 5 " << endl;
    cout << "-------------------------" << endl;
    cout << "Select an option: "; cin >> x;

    AccManager accmanager;

    while (x != 0) {
        switch (x) {
            case 1: accmanager.createAccount();
                break;
            case 2: library.buyBook();
                break;
        }
    cout << "Select an option: "; cin >> x;
    }


}