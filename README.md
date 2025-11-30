Мини библиотечна система – OOP Homework

Това е мини библиотечна система, реализирана на C++.
Целта на задачата е да се демонстрират основни и напреднали ООП концепции:
капсулация, конструктори, статични членове, const-коректност, валидации, Rule of 3/5, както и работа с няколко свързани класа

Структура на проекта

```
Author.h    – клас за автори
Book.h      – клас за книги (със статичен брояч)
Member.h    – клас за читатели
Loan.h      – клас за заеми
Library.h   – основен управляващ клас
main.cpp    – пример за демонстрация
```

Всички класове са реализирани изцяло в .h файлове, както е в примерното домашно, дадено от преподавателя („Автокъща“)

Компилация

Примерна команда за компилиране:

g++ -std=gnu++17 -Wall -Wextra -O2 -o library main.cpp

Стартиране:

./library


Описание на класовете:

Author

* string name
* int birthYear
* Конструктор по подразбиране и параметризиран конструктор
* Валидация: годината трябва да е в интервала 1850–2025
* Метод: string to_string() const
* Getters и setter с проверки
* Добри практики: const-коректност, списък за инициализация

Book

* string title
* Author author
* int year
* double price
* string isbn
* Статичен член: static int totalBooks
* Rule of 5: конструктори, оператори за копиране/преместване (default, тъй като няма ресурси)
* Валидации:

  * price >= 0
  * разумна година
* string to_string() const
* static int getTotalBooks()

Member

* string name
* string memberId
* int yearJoined
* Валидация: memberId ≠ празен
* Конструктор по подразбиране и параметризиран
* Метод: string to_string() const

Loan

* string isbn
* string memberId
* string startDate
* string dueDate
* bool returned
* Валидация: dueDate >= startDate
* Методи:

  * void markReturned()
  * bool isOverdue(const string& today) const
  * string to_string() const
* Сравнение на дати чрез лексикографски ред (YYYY-MM-DD)

Library

* vector<Book> books
* vector<Member> members
* vector<Loan> loans
* Методи:

  * void addBook(const Book& b)
  * void addMember(const Member& m)
  * bool hasBook(const string& isbn) const
  * bool isBookAvailable(const string& isbn) const
  * bool loanBook(const string& isbn, const string& memberId, const string& start, const string& due)
  * bool returnBook(const string& isbn, const string& memberId)
  * vector<Book> findByAuthor(const string& authorName) const
  * string to_string() const

Примерен изход

Library summary:
Books: 4
Members: 1
Active loans: 0

Zaemut e suzdaden uspeshno.
Nalichna li e ISBN-602? false
Nalichna li e ISBN-602? true

Knigi ot Elin Pelin:
 - Qn Bibiqn (1933), Elin Pelin (1877), 15.200000 lv, ISBN: ISBN-602
 - Pod manastirskata loza (1936), Elin Pelin (1877), 14.000000 lv, ISBN: ISBN-603
