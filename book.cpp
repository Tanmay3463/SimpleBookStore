#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;
    string publisher;
    int stock;
    float price;

    Book(string t, string a, string p, int s, float pr)
        : title(t), author(a), publisher(p), stock(s), price(pr) {}

    void display() const {
        cout << "📚 Title     : " << title << "\n"
             << "👤 Author    : " << author << "\n"
             << "🏢 Publisher : " << publisher << "\n"
             << "📦 Stock     : " << stock << "\n"
             << "💲 Price     : " << price << "\n\n";
    }
};

class BookStore {
private:
    vector<Book> books;

public:
    BookStore() {
        books.push_back(Book("OOP with C++", "Balaguruswamy", "TMH", 20, 120.5));
        books.push_back(Book("Programming with ANSI C", "Balaguruswamy", "TMH", 30, 110.0));
        books.push_back(Book("Electronic Circuit Theory", "S Chand", "S Chand Group", 45, 220.75));
        books.push_back(Book("Computer Algorithm", "Sri Manta Pal", "Pearson", 15, 115.75));
        books.push_back(Book("Computer Maths", "HK Das", "Laxmi Pub", 25, 140.5));
    }

    void displayAllBooks() const {
        cout << "\n📖 Available Books:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << "🔢 Book Index: " << i << "\n";
            books[i].display();
        }
    }

    int searchBook(const string& title, const string& author) const {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].title == title && books[i].author == author)
                return i;
        }
        return -1;
    }

    void buyBook() {
        cin.ignore();
        string title, author;
        cout << "\n🔍 Enter Book Title: ";
        getline(cin, title);
        cout << "🔍 Enter Author Name: ";
        getline(cin, author);

        int index = searchBook(title, author);
        if (index == -1) {
            cout << "❌ Book not found!\n";
            return;
        }

        cout << "\n✅ Book Found:\n";
        books[index].display();

        int quantity;
        cout << "🛒 Enter number of copies to buy: ";
        cin >> quantity;

        if (quantity <= books[index].stock) {
            float total = quantity * books[index].price;
            books[index].stock -= quantity;
            cout << "✅ Purchase successful! Total amount: ₹" << total << "\n";
        } else {
            cout << "❌ Not enough stock! Only " << books[index].stock << " copies available.\n";
        }
    }
};

int main() {
    BookStore store;
    int choice;

    do {
        cout << "\n======= 📚 Book Store Menu =======\n";
        cout << "1. Display All Books\n";
        cout << "2. Buy a Book\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.displayAllBooks();
                break;
            case 2:
                store.buyBook();
                break;
            case 3:
                cout << "👋 Thank you for visiting!\n";
                break;
            default:
                cout << "⚠️ Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
