#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;
    string genre;
    bool isAvailable;

    Book(const string& title, const string& author, const string& genre)
        : title(title), author(author), genre(genre), isAvailable(true) {}
};

int main() {
    vector<Book> library;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add New Book\n";
        cout << "2. Search for a Book\n";
        cout << "3. Borrow a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. List Available Books\n";
        cout << "6. Exit\n";

        int choice;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author, genre;
                cout << "Enter book title: ";
                cin.ignore(); // To clear the newline character left by previous cin
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter genre: ";
                getline(cin, genre);
                library.push_back(Book(title, author, genre));
                cout << "Book added successfully!\n";
                break;
            }
            case 2: {
                string searchTerm;
                cout << "Enter search term (title, author, or genre): ";
                cin.ignore();
                getline(cin, searchTerm);

                cout << "Search results:\n";
                bool found = false;
                for (const auto& book : library) {
                    if (book.title.find(searchTerm) != string::npos ||
                        book.author.find(searchTerm) != string::npos ||
                        book.genre.find(searchTerm) != string::npos) {
                        cout << "Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre << ", Availability: " << (book.isAvailable ? "Available" : "Borrowed") << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "No matching books found.\n";
                }
                break;
            }
            case 3: {
                string borrowTitle;
                cout << "Enter the title of the book you want to borrow: ";
                cin.ignore();
                getline(cin, borrowTitle);

                bool found = false;
                for (auto& book : library) {
                    if (book.title == borrowTitle) {
                        if (book.isAvailable) {
                            book.isAvailable = false;
                            cout << "You have successfully borrowed the book: " << book.title << endl;
                        } else {
                            cout << "The book is currently not available for borrowing.\n";
                        }
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found.\n";
                }
                break;
            }
            case 4: {
                string returnTitle;
                cout << "Enter the title of the book you want to return: ";
                cin.ignore();
                getline(cin, returnTitle);

                bool found = false;
                for (auto& book : library) {
                    if (book.title == returnTitle) {
                        if (!book.isAvailable) {
                            book.isAvailable = true;
                            cout << "You have successfully returned the book: " << book.title << endl;
                        } else {
                            cout << "The book is already available.\n";
                        }
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found.\n";
                }
                break;
            }
            case 5: {
                cout << "List of Available Books:\n";
                bool found = false;
                for (const auto& book : library) {
                    if (book.isAvailable) {
                        cout << "Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "No available books at the moment.\n";
                }
                break;
            }
            case 6: {
                cout << "Exiting the Library Management System. Goodbye!\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and
