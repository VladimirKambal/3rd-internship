#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    int year;
    int pages;
    bool available;

    bool isValidData(std::string title,
                     std::string author,
                     int year,
                     int pages) const;

public:
    // Конструктор
    Book(std::string title,
         std::string author,
         int year,
         int pages);

    // Геттеры
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    int getPages() const;
    bool isAvailable() const;

    // Сеттеры с валидацией
    void updateTitle(std::string new_title);
    void updateAuthor(std::string new_author);
    void updateYear(int new_year);
    void updatePages(int new_pages);

    // Управление состоянием книги
    void checkout();
    void returnBook();
};

std::string formatBookInfo(const Book& book);
bool isClassic(const Book& book);
double readingTime(const Book& book, int pages_per_day);
bool isOlder(const Book& first, const Book& second);

// Практика: передача по значению, по ссылке
void swap_titles_by_value(Book b1, Book b2);
void swap_titles_by_reference(Book& b1, Book& b2);

#endif