#include "book.h"

#include <iostream>
#include <stdexcept>

int main()
{
    std::setlocale(LC_ALL, "ru_RU"); 
    try
    {
        Book book(
            "Великий Гэтсби",
            "Фрэнсис Скотт Фицджеральд",
            1925,
            180
        );

        std::cout << "Исходная книга:\n";
        std::cout << formatBookInfo(book) << "\n\n";
        std::cout << "Попытка изменить год на 3000...\n";

        try
        {
            book.updateYear(3000);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Перехвачено исключение: "
                      << e.what()
                      << "\n\n";
        }

        book.updateTitle("Великий Гэтсби ? обновлённое издание");

        std::cout << "Название успешно изменено:\n";
        std::cout << formatBookInfo(book) << "\n\n";

        if (isClassic(book))
        {
            std::cout << "Книга является классикой.\n";
        }
        else
        {
            std::cout << "Книга не является классикой.\n";
        }

        int pages_per_day = 30;
        double days = readingTime(book, pages_per_day);

        std::cout << "Время чтения: "
                  << days
                  << " дн.\n\n";

        Book secondBook(
            "1984",
            "Джордж Оруэлл",
            1949,
            328
        );

        if (isOlder(book, secondBook))
        {
            std::cout << "\"" << book.getTitle()
                      << "\" старше, чем \""
                      << secondBook.getTitle()
                      << "\".\n";
        }
        else
        {
            std::cout << "\"" << book.getTitle()
                      << "\" не старше, чем \""
                      << secondBook.getTitle()
                      << "\".\n";
        }

        std::cout << "\nДо выдачи:\n";
        std::cout << formatBookInfo(book) << "\n";

        book.checkout();

        std::cout << "\nПосле выдачи:\n";
        std::cout << formatBookInfo(book) << "\n";

        book.returnBook();

        std::cout << "\nПосле возврата:\n";
        std::cout << formatBookInfo(book) << "\n";

        Book bookA("Хоббит", "Дж. Р. Р. Толкин", 1937, 310);
        Book bookB("Дюна", "Фрэнк Герберт", 1965, 412);

        // Часть 1. Передача по значению
        std::cout << "\n=== Часть 1: swap_titles_by_value ===\n";
        std::cout << "До:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";

        swap_titles_by_value(bookA, bookB);

        std::cout << "После:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";
        std::cout << "Названия в main не изменились: функция получила копии.\n";

        // Часть 2. Передача по ссылке
        std::cout << "\n=== Часть 2: swap_titles_by_reference ===\n";
        std::cout << "До:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";

        swap_titles_by_reference(bookA, bookB);

        std::cout << "После:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";

        // Часть 3. Const-ссылки
        std::cout << "\n=== Часть 3: is_older (const-ссылки) ===\n";
        const Book classicBook("Гордость и предубеждение", "Джейн Остин", 1813, 432);
        const Book modernBook("Хоббит", "Дж. Р. Р. Толкин", 1937, 310);

        if (is_older(classicBook, modernBook))
        {
            std::cout << classicBook.getTitle()
                      << " была издана раньше, чем "
                      << modernBook.getTitle() << ".\n";
        }
        else
        {
            std::cout << classicBook.getTitle()
                      << " была издана не раньше, чем "
                      << modernBook.getTitle() << ".\n";
        }

        // Часть 4. Передача указателей
        std::cout << "\n=== Часть 4: swap_titles_by_pointer ===\n";
        std::cout << "До:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";

        swap_titles_by_pointer(&bookA, &bookB);

        std::cout << "После:\n"
                  << "  bookA: " << bookA.getTitle() << "\n"
                  << "  bookB: " << bookB.getTitle() << "\n";

        std::cout << "Вызов обмена по указателям с nullptr безопасен: ";
        swap_titles_by_pointer(nullptr, &bookB);
        std::cout << "изменений не внесено.\n";

        // Часть 5. Проверка доступности
        std::cout << "\n=== Часть 5: is_book_available ===\n";
        Book availableBook("Чистый код", "Роберт К. Мартин", 2008, 464);

        std::cout << "Доступность книги "
                  << availableBook.getTitle() << ": "
                  << (is_book_available(&availableBook) ? "доступна" : "недоступна")
                  << "\n";

        availableBook.checkout();

        std::cout << "После выдачи: "
                  << (is_book_available(&availableBook) ? "доступна" : "недоступна")
                  << "\n";

        std::cout << "Передача nullptr: "
                  << (is_book_available(nullptr) ? "доступна" : "недоступна")
                  << " (nullptr обработан безопасно).\n";
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Ошибка: "
                  << e.what()
                  << "\n";
        return 1;
    }

    return 0;
}