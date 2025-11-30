#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <stdexcept>
#include "Author.h"

class Book {
private:
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

public:
    static int totalBooks;

    Book()
        : title("Unknown"), author(), year(1900), price(0), isbn("N/A")
    {
        totalBooks++;
    }

    Book(const std::string& t, const Author& a, int y, double p, const std::string& i)
        : title(t), author(a), year(y), price(p), isbn(i)
    {
        if (p < 0) throw std::invalid_argument("Price must be >= 0");
        if (y < 1500 || y > 2025) throw std::invalid_argument("Invalid year");
        if (i.empty()) throw std::invalid_argument("ISBN cannot be empty");
        totalBooks++;
    }

    // RULE OF 5 (defaulted)
    Book(const Book&) = default;
    Book(Book&&) noexcept = default;
    Book& operator=(const Book&) = default;
    Book& operator=(Book&&) noexcept = default;
    ~Book() = default;

    const std::string& getIsbn() const { return isbn; }
    const std::string& getTitle() const { return title; }
    const Author& getAuthor() const { return author; }

    int getYear() const { return year; }
    double getPrice() const { return price; }

    void setPrice(double p) {
        if (p < 0) throw std::invalid_argument("Price must be >= 0");
        price = p;
    }

    void setYear(int y) {
        if (y < 1500 || y > 2025) throw std::invalid_argument("Invalid year");
        year = y;
    }

    std::string to_string() const {
        return title + " (" + std::to_string(year) + "), " +
               author.to_string() + ", " +
               std::to_string(price) + " lv, ISBN: " + isbn;
    }

    static int getTotalBooks() { return totalBooks; }
};

int Book::totalBooks = 0;

#endif
