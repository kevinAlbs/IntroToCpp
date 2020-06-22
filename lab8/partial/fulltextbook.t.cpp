#include "fulltextbook.t.hpp"
#include "book.hpp"
#include "fulltextbook.hpp"

#include <cassert>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

using lab8::Book;
using lab8::FullTextBook;

void test_fulltextbook_getters() {
    FullTextBook b("Old Man and the Sea", "Hemingway", {"page 1", "page 2"});
    assert(b.title() == "Old Man and the Sea");
    assert(b.author() == "Hemingway");
    assert(b.pagecount() == 2);
}

void test_fulltextbook_const_getters() {
    const FullTextBook c("A Rebours", "Huysmans", {"page 1", "page 2", "page 3"});
    assert(c.title() == "A Rebours");
    assert(c.author() == "Huysmans");
    assert(c.pagecount() == 3);
}

void test_fulltextbook_get_page() {
    const FullTextBook c("Old Man and the Sea", "Hemingway", {"page 1", "page 2"});
    assert(c.get_page(0) == "page 1");
    assert(c.get_page(1) == "page 2");
}

void test_fulltextbook_stream_insertion() {
    {
        FullTextBook b("The Scarlet Letter", "Hawthorne", {"page 1", "page 2"});
        std::ostringstream oss;
        oss << b;
        std::string representation = oss.str();
        assert(representation == "The Scarlet Letter by Hawthorne (2 pages, full text)");
    }
    {
        const FullTextBook c("Catch-22", "Heller", {"page 1", "page 2", "page 3"});
        std::ostringstream oss;
        oss << c;
        std::string representation = oss.str();
        assert(representation == "Catch-22 by Heller (3 pages, full text)");
    }
    {
        FullTextBook ftb("Catch-22", "Heller", {"page 1", "page 2", "page 3"});
        const Book& c = ftb;
        std::ostringstream oss;
        oss << c;
        std::string representation = oss.str();
        assert(representation == "Catch-22 by Heller (3 pages, full text)");
    }
}

void test_fulltextbook_stream_insertion_chaining() {
    FullTextBook b("The Scarlet Letter", "Hawthorne", {"page 1", "page 2", "page 3"});
    std::ostringstream oss;
    oss << '.' << b << ".\n";
    std::string representation = oss.str();
    assert(representation == ".The Scarlet Letter by Hawthorne (3 pages, full text).\n");
}

void test_fulltextbook_virtual_destructor() {
    static_assert(std::has_virtual_destructor<Book>::value, "");
    std::unique_ptr<Book> p = std::make_unique<FullTextBook>(
        "The Scarlet Letter",
        "Hawthorne",
        std::vector<std::string>{"page 1", "page 2", "page 3", "page 4"}
    );
    p = nullptr;
    // We expect this test not to leak memory (which it will, if it calls the wrong destructor).
}
