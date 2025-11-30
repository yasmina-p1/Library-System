#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <stdexcept>

class Loan {
private:
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

public:
    Loan(const std::string& i, const std::string& m,
         const std::string& s, const std::string& d)
         : isbn(i), memberId(m), startDate(s), dueDate(d), returned(false)
    {
        if (d < s)
            throw std::invalid_argument("Due date must be >= start date.");
    }

    void markReturned() { returned = true; }
    bool isReturned() const { return returned; }

    bool isOverdue(const std::string& today) const {
        return (!returned && today > dueDate);
    }

    const std::string& getIsbn() const { return isbn; }
    const std::string& getMemberId() const { return memberId; }
    bool isActive() const { return !returned; }

    std::string to_string() const {
        return "Loan: " + isbn + " -> " + memberId +
               " (" + startDate + " to " + dueDate + ") " +
               (returned ? "[returned]" : "[active]");
    }
};

#endif
