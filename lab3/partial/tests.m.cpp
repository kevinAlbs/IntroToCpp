#include "book.hpp"
#include "library.hpp"

#include <cassert>
#include <cstdio>
#include <string>

static void test_book_getters() {
    lab3::Book b("Old Man and the Sea", "Hemingway", 100);
    assert(b.title() == "Old Man and the Sea");
    assert(b.author() == "Hemingway");
    assert(b.pagecount() == 100);
}

static void test_constness_of_book_getters() {
    const lab3::Book c("A Rebours", "Huysmans", 400);
    assert(c.title() == "A Rebours");
    assert(c.author() == "Huysmans");
    assert(c.pagecount() == 400);
}

static void test_book_swap() {
    lab3::Book b1("Old Man and the Sea", "Hemingway", 100);
    lab3::Book b2("A Rebours", "Huysmans", 400);
    b1.swap(b2);
    assert(b1.title() == "A Rebours");
    assert(b1.author() == "Huysmans");
    assert(b1.pagecount() == 400);
    assert(b2.title() == "Old Man and the Sea");
    assert(b2.author() == "Hemingway");
    assert(b2.pagecount() == 100);
}

static void test_library_addbook() {
    lab3::Library lib;
    assert(lib.bookcount() == 0);
    assert(lib.pagecount() == 0);

    auto b = lab3::Book("Old Man and the Sea", "Hemingway", 100);
    lib.add_book(b);
    assert(lib.bookcount() == 1);
    assert(lib.pagecount() == 100);

    lib.add_book(lab3::Book("A Rebours", "Huysmans", 400));
    assert(lib.bookcount() == 2);
    assert(lib.pagecount() == 500);
}

static void test_library_removebooks() {
    using namespace lab3;

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

int main() {
    test_book_getters();
    test_constness_of_book_getters();
    test_book_swap();
    test_library_addbook();
    test_library_removebooks();

    std::puts("If you're seeing this line, it means all tests passed.");
}
