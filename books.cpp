#include <iostream>
#include <string.h>
#define SIZE_OF_CHAR 50

using namespace std;

class Book {
private:
    int *price, *stock;
    char *name, *author, *publisher;
public:
    int static total_stock;
    // This constructor perform the allocation for the variables in the class.
    Book() {
        price = new int;
        stock = new int;
        name = new char[SIZE_OF_CHAR];
        author = new char[SIZE_OF_CHAR];
        publisher = new char[SIZE_OF_CHAR];
        *stock = 0;
    }
    // This function perform the get the class variable.
    void getData() {
        total_stock = total_stock - *stock;
        cout << "Enter the Name, Author, Publisher, Price, Stock: ";
        cin >> name >> author >> publisher >> *price >> *stock;
        total_stock = total_stock + (*stock);
    }
    // This function perform the put the data in the variables.
    void putData() {
        cout << name << "\t" << author << "\t" << publisher << "\t\t" << *price << "\t" << *stock << endl;
    }
    // This function get two params name and the author it checks the params are equals to the class data if they match it return true else false
    bool search(char *name, char *author) {
        return (strcmp(this -> name, name) == 0 && strcmp(this -> author, author) == 0);
    }
    // This function get the quantity of the books and decrement the stock of the books.
    void purchase() {
        int qty;
        cout << "Enter quantity of books: ";
        cin >> qty;
        if (qty > (*this -> stock)) {
            cout << "Stock is not available";
        }
        cout << "Total cost of books is " << qty * (*this -> price);
        *(this -> stock) =  *(this -> stock) - qty;
        Book::total_stock = Book::total_stock - qty;
    }
};

int Book::total_stock = 0;

int main() {
    Book *books[10];
    int choice, currentBook = 0;
    char author[SIZE_OF_CHAR], name[SIZE_OF_CHAR];
    while (1) {
        cout << "\nMenu\n1.Add Book\n2.Display Books\n3.Search\n4.Purchase\n5.Search and update\n6.Get total books count\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                books[currentBook] = new Book();
                books[currentBook++] -> getData();
                break;
            case 2:
                cout << "Name\tAuthor\tPublisher\t\tPrice\tStock\n";
                for (choice = 0; choice < currentBook; choice++)
                    books[choice] -> putData();
                break;
            case 5:
                cout << "Enter name and author of book to search: ";
                cin >> name >> author;
                for (choice = 0; choice < currentBook; choice++)
                    if (books[choice] -> search(name, author))
                        break;
                if (choice == currentBook)
                    cout << "Book not found";
                else {
                    cout << "Name\tAuthor\tPublisher\t\tPrice\tStock\n";
                    books[choice] -> putData();
                    books[choice] -> getData();
                }
                break;
            case 4:
                cout << "Enter name and author of book to search: ";
                cin >> name >> author;
                for (choice = 0; choice < currentBook; choice++)
                    if (books[choice] -> search(name, author))
                        break;
                if (choice == currentBook)
                    cout << "Book not found";
                else
                    books[choice] -> purchase();
                break;
            case 3:
                cout << "Enter name and author of book to search: ";
                cin >> name >> author;
                for (choice = 0; choice < currentBook; choice++)
                    if (books[choice] -> search(name, author))
                        break;
                if (choice == currentBook)
                    cout << "Book not found";
                else {
                    cout << "Name\tAuthor\tPublisher\t\tPrice\tStock\n";
                    books[choice] -> putData();
                }
                break;
            case 6:
                cout << "Total count is " << Book::total_stock << endl;
                break;
            default:
                cout << "Invalid choice given";
        }
    }
}
