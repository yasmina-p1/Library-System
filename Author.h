#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <stdexcept>

class Author {
private:
    std::string name;
    int birthYear;

public:
    Author() : name("Unknown"), birthYear(1900) {}

    Author(const std::string& n, int by)
        : name(n), birthYear(by)
    {
        if (by < 1848 || by > 2025) 
            throw std::invalid_argument("Invalid birth year.");
    }

    const std::string& getName() const { return name; }
    int getBirthYear() const { return birthYear; }

    void setBirthYear(int y) {
        if (y < 1848 || y > 2025)
            throw std::invalid_argument("Invalid birth year.");
        birthYear = y;
    }

    std::string to_string() const {
        return name + " (" + std::to_string(birthYear) + ")";
    }
};

#endif
