#include "book.t.hpp"
#include "book.hpp"

#include <cassert>
#include <sstream>
#include <string>

using lab6::Book;

void test_book_getters() {
    Book b("Old Man and the Sea", "Hemingway", 100);
    assert(b.title() == "Old Man and the Sea");
    assert(b.author() == "Hemingway");
    assert(b.pagecount() == 100);
}

void test_book_const_getters() {
    const Book c("A Rebours", "Huysmans", 400);
    assert(c.title() == "A Rebours");
    assert(c.author() == "Huysmans");
    assert(c.pagecount() == 400);
}

void test_book_stream_insertion() {
    {
        Book b("The Scarlet Letter", "Hawthorne", 200);
        std::ostringstream oss;
        oss << b;
        std::string representation = oss.str();
        assert(representation == "The Scarlet Letter by Hawthorne (200 pages)");
    }
    {
        const Book c("Catch-22", "Heller", 450);
        std::ostringstream oss;
        oss << c;
        std::string representation = oss.str();
        assert(representation == "Catch-22 by Heller (450 pages)");
    }
}

void test_book_stream_insertion_chaining() {
    Book b("The Scarlet Letter", "Hawthorne", 200);
    std::ostringstream oss;
    oss << '.' << b << ".\n";
    std::string representation = oss.str();
    assert(representation == ".The Scarlet Letter by Hawthorne (200 pages).\n");
}
