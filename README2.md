# Проект: Библиотечна система (Library System)

## Описание

Проектът **„Библиотечна система“** представлява малка C++ система, която моделира работа с книги, автори и читатели чрез няколко взаимосвързани класа — `Author`, `Book`, `Member`, `Loan` и `Library`.
Той демонстрира прилагането на основни обектно-ориентирани концепции в C++:

* конструктори и деструктори;
* капсулация и достъп чрез getters и setters;
* `const`-коректност и валидация на данни;
* статични членове и методи;
* прилагане на принципите на Rule of 3/5;
* добри ООП практики в реалистичен контекст.

---

## Структура на проекта

```
library/
├── Author.h
├── Book.h
├── Member.h
├── Loan.h
├── Library.h
├── README.md
├── main.cpp
└── image.png
```

---

## Компилация и изпълнение

Отворете терминал в директорията `library/` и изпълнете:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o library
```

След това стартирайте програмата:

```bash
./library
```

---

## Примерен изход

```
Library overview:
  Books: 2
  Members: 1
  Active loans: 1

Loan created.
Available ISBN-001? false
Book returned.
Available ISBN-001? true

Books by Ivan Vazov:
  - Pod igoto (1894) - 25.50 лв.
  - Nema zemya (1900) - 18.90 лв.

Total books created: 2
```

---

## Класове

### Клас `Author`

Представя автор с основни характеристики.

**Членове:**

* `std::string name` — име на автора
* `int birthYear` — година на раждане

**Методи:**

* конструктор по подразбиране и параметризиран
* `setBirthYear(int)` с валидация (1850–2025)
* `to_string()` — връща текстово описание на автора

---

### Клас `Book`

Представя книга с информация за автора, година, цена и ISBN.

**Членове:**

* `std::string title`
* `Author author`
* `int year`
* `double price`
* `std::string isbn`
* `static int totalBooks` — брояч на живите инстанции

**Методи:**

* конструктори (по подразбиране, параметризиран, копиращ, преместващ)
* оператори Rule of 5
* валидирани setters
* `to_string()`
* `static getTotalBooks()`

---

### Клас `Member`

Представя читател на библиотеката.

**Членове:**

* `std::string name`
* `std::string memberId`
* `int yearJoined`

**Методи:**

* конструктори по подразбиране и параметризирани
* валидация на `memberId`
* `to_string()`

---

### Клас `Loan`

Представя заем на книга от читател.

**Членове:**

* `std::string isbn`
* `std::string memberId`
* `std::string startDate`
* `std::string dueDate`
* `bool returned`

**Методи:**

* конструктор с валидация (`dueDate >= startDate`)
* `markReturned()`
* `isOverdue(const std::string& today) const`
* `to_string()`

---

### Клас `Library`

Управлява книги, читатели и заеми.

**Членове:**

* `std::vector<Book> books`
* `std::vector<Member> members`
* `std::vector<Loan> loans`

**Методи:**

* `addBook(const Book&)`
* `addMember(const Member&)`
* `hasBook(const std::string& isbn) const`
* `isBookAvailable(const std::string& isbn) const`
* `loanBook(...)`
* `returnBook(...)`
* `findByAuthor(const std::string& authorName) const`
* `to_string()`

---

## Образователни цели

Проектът има за цел да демонстрира:

* разделение между интерфейс (`.h`) и имплементация (`.cpp`)
* използване на списъци за инициализация
* валидация на данни и поддържане на инварианти
* работа със статични членове
* прилагане на const-коректност и принципите на Rule of 3/5

---

## Екранна снимка

![screenshot](/image.png)

---

## Автор

**Име:** *[Ясмина Ричанек]*
**Номер:** *[28]*
**Курс:** 225 
**Дата:** *[02.12.2025]*
