#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Structure to represent a book
struct Book {
    string title;
    string author;
    string isbn;
    double price;
    int quantity;
};

// Function to add a new book to the inventory
void addBook(vector<Book>& inventory) {
    Book newBook;
    cout << "Enter title: ";
    getline(cin >> ws, newBook.title);
    cout << "Enter author: ";
    getline(cin >> ws, newBook.author);
    cout << "Enter ISBN: ";
    cin >> newBook.isbn;
    cout << "Enter price: ";
    cin >> newBook.price;
    cout << "Enter quantity: ";
    cin >> newBook.quantity;

    inventory.push_back(newBook);
    cout << "Book added to inventory.\n";
}

// Function to remove a book from the inventory by ISBN
void removeBook(vector<Book>& inventory, const string& isbn) {
    auto it = inventory.begin();
    while (it != inventory.end()) {
        if (it->isbn == isbn) {
            it = inventory.erase(it);
            cout << "Book removed from inventory.\n";
            return;
        }
        else {
            ++it;
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n";
}

// Function to update book details by ISBN
void updateBook(vector<Book>& inventory, const string& isbn) {
    for (auto& book : inventory) {
        if (book.isbn == isbn) {
            cout << "Enter new title: ";
            getline(cin >> ws, book.title);
            cout << "Enter new author: ";
            getline(cin >> ws, book.author);
            cout << "Enter new price: ";
            cin >> book.price;
            cout << "Enter new quantity: ";
            cin >> book.quantity;
            cout << "Book details updated.\n";
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n";
}

// Function to display all books in the inventory
void displayBooks(const vector<Book>& inventory) {
    cout << "Books in inventory:\n";
    for (const auto& book : inventory) {
        cout << "Title: " << book.title << ", Author: " << book.author
             << ", ISBN: " << book.isbn << ", Price: $" << book.price
             << ", Quantity: " << book.quantity << endl;
    }
}

// Function to search for a book by ISBN
void searchBook(const vector<Book>& inventory, const string& isbn) {
    for (const auto& book : inventory) {
        if (book.isbn == isbn) {
            cout << "Book found:\n";
            cout << "Title: " << book.title << ", Author: " << book.author
                 << ", ISBN: " << book.isbn << ", Price: $" << book.price
                 << ", Quantity: " << book.quantity << endl;
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n";
}

int main() {
    vector<Book> inventory;
    char choice;
    string isbn;

    do {
        cout << "\nBookstore Inventory Management System\n";
        cout << "1. Add a new book\n";
        cout << "2. Remove a book\n";
        cout << "3. Update book details\n";
        cout << "4. Display all books\n";
        cout << "5. Search for a book by ISBN\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addBook(inventory);
                break;
            case '2':
                cout << "Enter ISBN of the book to remove: ";
                cin >> isbn;
                removeBook(inventory, isbn);
                break;
            case '3':
                cout << "Enter ISBN of the book to update: ";
                cin >> isbn;
                updateBook(inventory, isbn);
                break;
            case '4':
                displayBooks(inventory);
                break;
            case '5':
                cout << "Enter ISBN of the book to search: ";
                cin >> isbn;
                searchBook(inventory, isbn);
                break;
            case '6':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '6');

    return 0;
}
