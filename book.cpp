#include "book.h"

#include <stdexcept>
#include <sstream>

// Конструктор
Book::Book(std::string title,std::string author,int year,int pages): title(title),author(author),year(year),pages(pages),available(true)
{
    if (!isValidData(title, author, year, pages))
    {
        throw std::invalid_argument("Invalid book data");
    }
}

// Приватный метод валидации
bool Book::isValidData(std::string title,std::string author,int year,int pages) const
{
    if (title.empty())
    {
        return false;}
    if (author.empty())
    {
        return false;}
    if (year < 1450 || year > 2025)
    {
        return false;}
    if (pages <= 0)
    {
        return false;}
    return true;
}
// Геттеры
std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

int Book::getYear() const
{
    return year;
}

int Book::getPages() const
{
    return pages;
}

bool Book::isAvailable() const
{
    return available;
}
// Сеттер названия
void Book::updateTitle(std::string new_title)
{
    if (!isValidData(new_title, author, year, pages))
    {
        throw std::invalid_argument(
            "Invalid title: title cannot be empty"
        );
    }

    title = new_title;
}
// Сеттер автора
void Book::updateAuthor(std::string new_author)
{
    if (!isValidData(title, new_author, year, pages))
    {
        throw std::invalid_argument(
            "Invalid author: author cannot be empty"
        );
    }

    author = new_author;
}
// Сеттер года
void Book::updateYear(int new_year)
{
    if (!isValidData(title, author, new_year, pages))
    {
        throw std::invalid_argument(
            "Invalid year: year must be between 1450 and 2025"
        );
    }

    year = new_year;
}
// Сеттер количества страниц
void Book::updatePages(int new_pages)
{
    if (!isValidData(title, author, year, new_pages))
    {
        throw std::invalid_argument(
            "Invalid pages: number of pages must be greater than 0"
        );
    }

    pages = new_pages;
}
// Взять книгу
void Book::checkout()
{
    if (!available)
    {
        throw std::invalid_argument(
            "Book is already checked out"
        );
    }

    available = false;
}
// Вернуть книгу
void Book::returnBook()
{
    if (available)
    {
        throw std::invalid_argument(
            "Book is already available"
        );
    }

    available = true;
}
// Форматирование информации
std::string formatBookInfo(const Book& book)
{
    std::ostringstream result;

    result << "Title: " << book.getTitle()
           << ", Author: " << book.getAuthor()
           << ", Year: " << book.getYear()
           << ", Pages: " << book.getPages()
           << ", Status: "
           << (book.isAvailable() ? "Available" : "Checked Out");

    return result.str();
}
// Проверка на классику
bool isClassic(const Book& book)
{
    return book.getYear() < 1975;
}
// Вычисление времени чтения
double readingTime(const Book& book, int pages_per_day)
{
    if (pages_per_day <= 0)
    {
        throw std::invalid_argument(
            "Pages per day must be greater than 0"
        );
    }

    return static_cast<double>(book.getPages()) / pages_per_day;
}
// Cравнение двух книг
bool isOlder(const Book& first, const Book& second)
{
    return first.getYear() < second.getYear();
}
// Обмен названий по значению: работает с КОПИЯМИ, оригиналы не меняются
void swap_titles_by_value(Book b1, Book b2)
{
    std::string temp = b1.getTitle();
    b1.updateTitle(b2.getTitle());
    b2.updateTitle(temp);
}
// Обмен названий по ссылке: работает с самими объектами
void swap_titles_by_reference(Book& b1, Book& b2)
{
    std::string temp = b1.getTitle();
    b1.updateTitle(b2.getTitle());
    b2.updateTitle(temp);
}
