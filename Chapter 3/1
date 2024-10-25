#include <iostream>
#include <vector>
#include <string>

class Book {
protected:
    std::string title;
public:
    Book(std::string title) : title(title) {}
    virtual void display() const {
        std::cout << "Book: " << title << std::endl;
    }
};

class Textbook : public Book {
private:
    std::string subject;
public:
    Textbook(std::string title, std::string subject) : Book(title), subject(subject) {}
    void display() const override {
        std::cout << "Textbook: " << title << " on " << subject << std::endl;
    }
};

class Library {
private:
    std::vector<Book*> books;
public:
    void addBook(Book* book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const auto& book : books) {
            book->display();
        }
    }

    ~Library() {
        for (auto& book : books) {
            delete book;
        }
    }
};

int main() {
    Library library;
    library.addBook(new Book("1984"));
    library.addBook(new Textbook("Physics", "Science"));

    library.displayBooks();
    return 0;
}
