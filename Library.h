#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void addMember(const Member& m) {
        members.push_back(m);
    }

    bool hasBook(const std::string& isbn) const {
        return std::any_of(books.begin(), books.end(),
            [&](const Book& b){ return b.getIsbn() == isbn; });
    }

    bool isBookAvailable(const std::string& isbn) const {
        return std::none_of(loans.begin(), loans.end(),
            [&](const Loan& l){ return l.getIsbn() == isbn && l.isActive(); });
    }

    bool loanBook(const std::string& isbn, const std::string& memberId,
                  const std::string& start, const std::string& due)
    {
        if (!hasBook(isbn)) return false;
        if (!isBookAvailable(isbn)) return false;

        loans.emplace_back(isbn, memberId, start, due);
        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& l : loans) {
            if (l.getIsbn() == isbn && l.getMemberId() == memberId && l.isActive()) {
                l.markReturned();
                return true;
            }
        }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& b : books)
            if (b.getAuthor().getName().find(authorName) != std::string::npos)
                result.push_back(b);
        return result;
    }

    std::string to_string() const {
        int activeLoans = 0;
        for (const auto& l : loans)
            if (l.isActive()) activeLoans++;

        return "Library summary:\nBooks: " + std::to_string(books.size()) +
               "\nMembers: " + std::to_string(members.size()) +
               "\nActive loans: " + std::to_string(activeLoans);
    }
};

#endif
