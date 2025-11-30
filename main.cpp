#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;

    Author a1{"Hristo Botev", 1848};
    Author a2{"Elin Pelin", 1877};
    Author a3{"Ivan Vazov", 1850};

    Book b1{"Stihotvorqniq", a1, 1875, 12.50, "ISBN-501"};
    Book b2{"Qn Bibiqn", a2, 1933, 15.20, "ISBN-602"};
    Book b3{"Pod manastirskata loza", a2, 1936, 14.00, "ISBN-603"};
    Book b4{"Nemili-nedragi", a3, 1883, 11.80, "ISBN-704"};

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);
    lib.addBook(b4);

    lib.addMember(Member{"Stoqn Petrov", "ST202", 2023});

    cout << lib.to_string() << "\n\n";

    if (lib.loanBook("ISBN-602", "ST202", "2025-12-01", "2025-12-15"))
        cout << "Zaemut e suzdaden uspeshno.\n";

    cout << "Nalichna li e ISBN-602? "
         << boolalpha << lib.isBookAvailable("ISBN-602") << "\n";

    lib.returnBook("ISBN-602", "ST202");

    cout << "Nalichna li e ISBN-602? "
         << boolalpha << lib.isBookAvailable("ISBN-602") << "\n\n";

    cout << "Knigi ot Elin Pelin:\n";
    for (const auto& bk : lib.findByAuthor("Pelin")) {
        cout << " - " << bk.to_string() << "\n";
    }
}
