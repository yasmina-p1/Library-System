#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <stdexcept>

class Member {
private:
    std::string name;
    std::string memberId;
    int yearJoined;

public:
    Member()
        : name("Unknown"), memberId("N/A"), yearJoined(2000) {}

    Member(const std::string& n, const std::string& id, int y)
        : name(n), memberId(id), yearJoined(y)
    {
        if (id.empty()) throw std::invalid_argument("memberId cannot be empty");
    }

    const std::string& getName() const { return name; }
    const std::string& getId() const { return memberId; }

    std::string to_string() const {
        return name + " (" + memberId + ", " + std::to_string(yearJoined) + ")";
    }
};

#endif
