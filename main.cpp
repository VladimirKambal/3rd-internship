#include "book.h"

#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        Book book(
            "The Great Gatsby",
            "F. Scott Fitzgerald",
            1925,
            180
        );

        std::cout << "Initial book:\n";
        std::cout << formatBookInfo(book) << "\n\n";
        std::cout << "Trying to update year to 3000...\n";

        try
        {
            book.updateYear(3000);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Exception caught: "
                      << e.what()
                      << "\n\n";
        }
        book.updateTitle("The Great Gatsby - Updated");

        std::cout << "Title successfully updated:\n";
        std::cout << formatBookInfo(book) << "\n\n";
        if (isClassic(book))
        {
            std::cout << "The book is a classic.\n";
        }
        else
        {
            std::cout << "The book is not a classic.\n";
        }

        int pages_per_day = 30;

        double days = readingTime(book, pages_per_day);

        std::cout << "Reading time: "
                  << days
                  << " days\n\n";

        Book secondBook(
            "1984",
            "George Orwell",
            1949,
            328
        );
        if (isOlder(book, secondBook))
        {
            std::cout << "\"" << book.getTitle()
                      << "\" is older than \""
                      << secondBook.getTitle()
                      << "\".\n";
        }
        else
        {
            std::cout << "\"" << book.getTitle()
                      << "\" is not older than \""
                      << secondBook.getTitle()
                      << "\".\n";
        }
        std::cout << "\nBefore checkout:\n";
        std::cout << formatBookInfo(book) << "\n";

        book.checkout();

        std::cout << "\nAfter checkout:\n";
        std::cout << formatBookInfo(book) << "\n";

        book.returnBook();

        std::cout << "\nAfter returning:\n";
        std::cout << formatBookInfo(book) << "\n";

        Book bookA("The Hobbit", "J.R.R. Tolkien", 1937, 310);
        Book bookB("Dune", "Frank Herbert", 1965, 412);

        std::cout << "\n=== Part 1: swap_titles_by_value ===\n";
        std::cout << "Before:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";

        swap_titles_by_value(bookA, bookB);

        std::cout << "After:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";

        std::cout << "\n=== Part 2: swap_titles_by_reference ===\n";
        std::cout << "Before:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";

        swap_titles_by_reference(bookA, bookB);

        std::cout << "After:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Error: "
                  << e.what()
                  << "\n";
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}