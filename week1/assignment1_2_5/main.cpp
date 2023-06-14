#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

std::string get_user_string()
{
    while (true)
    {
        std::string value{};
        std::cout << "Please input string value: ";
        std::getline(std::cin, value);
        if (!value.empty())
        {
            return value;
        }
    }
}
int get_user_int()
{
    while (true)
    {
        int value{};
        std::cout << "Please input integer value: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

struct Book
{
    std::string m_author{};
    std::string m_title{};
    std::string m_ISBN{};
    int m_year{};
    int m_quantity{};
    int m_loaned{};

    Book(const std::string& author, const std::string& title, const std::string& isbn, const int year, const int quantity)
        : m_author{ author }, m_title{ title }, m_ISBN{ isbn }, m_year{ year }, m_quantity{ quantity }
        {}

    friend std::ostream& operator<<(std::ostream& ostream, const Book& book);
};
std::ostream& operator<<(std::ostream& ostream, const Book& book)
{
    ostream << book.m_author << " - " << book.m_title << " (" << book.m_ISBN
        << ") - " << book.m_year << "\nQuantity: " << book.m_quantity
        << " Available:" << book.m_quantity - book.m_loaned << '\n';
    return ostream;
}
namespace Library
{
    std::vector<Book> local_library{};

    void sort_library(std::vector<Book>& library)
    {
        std::sort(library.begin(), library.end(),
            [](const auto& a, const auto& b) {
                return ( a.m_author < b.m_author );
            });
    }
        void display_book(std::vector<Book>& library)
    {
        int counter{ 0 };
        int choice;
        std::cout << "Please choose the book to display from the list:\n\n";
        std::cout << "Give negative value to exit.\n\n";

        for (auto& book : library)
        {
            std::cout << counter << ") " << book.m_author << " - " << book.m_title
                << " (" << book.m_year << ")\n";
            ++counter;
        }
        std::cin >> choice;

        if (choice < 0)
        {
            std::cout << "Exiting.\n\n";
            return;
        } 
        else
        {
            std::cout << "Chosen book to display: " << library.at(choice) << "\n\n";
            return;
        }
    }
    void add_book(std::vector<Book>& library)
    {
        std::cout << "Author:\n";
        std::string author{get_user_string()};
        std::cout << "Title:\n";
        std::string title{get_user_string()};
        std::cout << "ISBN:\n";
        std::string isbn{get_user_string()};
        std::cout << "Year:\n";
        int year{get_user_int()};
        std::cout << "Quantity:\n";
        int quantity{ get_user_int() };
        std::cout << "\n\n";

        library.push_back(Book{ author, title, isbn, year, quantity });
        sort_library(library);
    }
    void delete_book(std::vector<Book>& library)
    {
        int counter{ 0 };
        int choice;
        std::cout << "Please choose the book to delete from the list:\n\n";
        std::cout << "Give negative value to cancel the deletion!\n\n";

        for (auto& book : library)
        {
            std::cout << counter << ") " << book.m_author << " - " << book.m_title
                << " (" << book.m_year << ")\n";
            ++counter;
        }
        std::cin >> choice;

        if (choice < 0)
        {
            std::cout << "Canceling the delete.\n\n";
            return;
        }
        else
        {
            std::cout << "Deleting...\n\n";
            library.erase(library.begin() + choice);
        }
    }
    bool currently_at_library(Book& book)
    {
        if (book.m_quantity > book.m_loaned)
        {
            std::cout << "The book " << book << " is available.\n\n";
            return true;
        }
        else
        {
            std::cout << "The book " << book << " is currently unavailable.\n\n";
            return false;       
        }
    }
    void loan_book(std::vector<Book>& library)
    {
        int counter{ 0 };
        int choice;
        std::cout << "Please choose the book to loan from the list:\n\n";
        std::cout << "Give negative value to cancel the loan!\n\n";

        for (auto& book : library)
        {
            std::cout << counter << ") " << book.m_author << " - " << book.m_title
                << " (" << book.m_year << ")\n";
            ++counter;
        }
        std::cin >> choice;

        if (choice < 0)
        {
            std::cout << "Canceling the loan.\n\n";
            return;
        }
        else if (!currently_at_library(library.at(choice)))
        {
            return;
        }
        else
        {
            ++library.at(choice).m_loaned;
            std::cout << "Succesfully loaned: " << library.at(choice) << "\n\n";
            return;
        }
    }

}
int main()
{
    Library::add_book(Library::local_library);
    Library::local_library.push_back(Book{ "Teppo Tuomonen", "Tähtien sota", "978-3-16-148410-0", 1990, 2 });
    Library::local_library.push_back(Book{ "Kalle Kakko", "Kokkisota", "978-3-16-142310-0", 1991, 3 });
    Library::local_library.push_back(Book{ "Raija Rantanen", "Rocki-sota", "978-3-16-148410-0", 1994, 5 });
    Library::sort_library(Library::local_library);
    
    Library::display_book(Library::local_library);
    Library::delete_book(Library::local_library);
    Library::loan_book(Library::local_library);
    Library::loan_book(Library::local_library);
    Library::loan_book(Library::local_library);

    return 0;
}
