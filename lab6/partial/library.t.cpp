#include "book.hpp"
#include "library.hpp"

#include <cassert>

using lab6::Book;
using lab6::Library;

void test_library_addbook() {
    Library lib;
    assert(lib.bookcount() == 0);
    assert(lib.pagecount() == 0);

    auto b = Book("Old Man and the Sea", "Hemingway", 100);
    lib.add_book(b);
    assert(lib.bookcount() == 1);
    assert(lib.pagecount() == 100);

    lib.add_book(Book("The Curious Incident of the Dog in the Night-Time", "Haddon", 226));
    assert(lib.bookcount() == 2);
    assert(lib.pagecount() == 326);
}

void test_library_removebooks_by_title() {
    Library lib;
    lib.add_book(Book("Old Man and the Sea", "Hemingway", 100));
    lib.add_book(Book("A Rebours", "Huysmans", 400));
    lib.add_book(Book("I Am a Strange Loop", "Hofstadter", 800));
    lib.add_book(Book("Death in the Afternoon", "Hemingway", 120));
    lib.add_book(Book("A Farewell to Arms", "Hemingway", 250));
    lib.remove_books_by_title("A Farewell to Arms");
    assert(lib.bookcount() == 4);
    lib.remove_books_by_title("Catch-22");  // should not be found
    assert(lib.bookcount() == 4);
    lib.remove_books_by_title("A Rebours");
    assert(lib.bookcount() == 3);
}

void test_library_removebooks_by_author() {
    Library lib;
    lib.add_book(Book("Old Man and the Sea", "Hemingway", 100));
    lib.add_book(Book("A Rebours", "Huysmans", 400));
    lib.add_book(Book("I Am a Strange Loop", "Hofstadter", 800));
    lib.add_book(Book("Death in the Afternoon", "Hemingway", 120));
    lib.add_book(Book("A Farewell to Arms", "Hemingway", 250));
    lib.remove_books_by_author("Hemingway");
    assert(lib.bookcount() == 2);
    lib.remove_books_by_author("Hemingway");
    assert(lib.bookcount() == 2);
}

void test_library_iteration() {
    Library lib;
    lib.add_book(Book("Old Man and the Sea", "Hemingway", 100));
    lib.add_book(Book("A Rebours", "Huysmans", 400));
    lib.add_book(Book("I Am a Strange Loop", "Hofstadter", 800));
    lib.add_book(Book("Death in the Afternoon", "Hemingway", 120));
    lib.add_book(Book("The Curious Incident of the Dog in the Night-Time", "Haddon", 226));
    std::string initials = "";
    for (Book& b : lib) {
        initials += b.author()[0];
    }
    assert(initials == "HHHHH");
}

void test_library_const_iteration() {
    Library lib;
    lib.add_book(Book("Old Man and the Sea", "Hemingway", 100));
    lib.add_book(Book("A Rebours", "Huysmans", 400));
    lib.add_book(Book("I Am a Strange Loop", "Hofstadter", 800));
    lib.add_book(Book("Death in the Afternoon", "Hemingway", 120));
    lib.add_book(Book("The Curious Incident of the Dog in the Night-Time", "Haddon", 226));
    std::string initials = "";
    for (const Book& b : static_cast<const Library&>(lib)) {
        initials += b.author()[0];
    }
    assert(initials == "HHHHH");
}
