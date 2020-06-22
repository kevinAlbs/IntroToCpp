#include "kindlebook.t.hpp"
#include "book.hpp"
#include "kindlebook.hpp"

#include <cassert>
#include <sstream>
#include <string>

using lab8::Book;
using lab8::KindleBook;

void test_kindlebook_getters() {
    KindleBook b("Old Man and the Sea", "Hemingway");
    assert(b.title() == "Old Man and the Sea");
    assert(b.author() == "Hemingway");
    assert(b.pagecount() == 0);
}

void test_kindlebook_const_getters() {
    const KindleBook c("A Rebours", "Huysmans");
    assert(c.title() == "A Rebours");
    assert(c.author() == "Huysmans");
    assert(c.pagecount() == 0);
}

void test_kindlebook_stream_insertion() {
    {
        KindleBook b("The Scarlet Letter", "Hawthorne");
        std::ostringstream oss;
        oss << b;
        std::string representation = oss.str();
        assert(representation == "The Scarlet Letter by Hawthorne (0 pages, Kindle)");
    }
    {
        const KindleBook c("Catch-22", "Heller");
        std::ostringstream oss;
        oss << c;
        std::string representation = oss.str();
        assert(representation == "Catch-22 by Heller (0 pages, Kindle)");
    }
    {
        KindleBook kb("Catch-22", "Heller");
        const Book& c = kb;
        std::ostringstream oss;
        oss << c;
        std::string representation = oss.str();
        assert(representation == "Catch-22 by Heller (0 pages, Kindle)");
    }
}

void test_kindlebook_stream_insertion_chaining() {
    KindleBook b("The Scarlet Letter", "Hawthorne");
    std::ostringstream oss;
    oss << '.' << b << ".\n";
    std::string representation = oss.str();
    assert(representation == ".The Scarlet Letter by Hawthorne (0 pages, Kindle).\n");
}
