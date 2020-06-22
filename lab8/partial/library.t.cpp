#include "fulltextbook.hpp"
#include "kindlebook.hpp"
#include "library.hpp"

#include <cassert>

using lab8::FullTextBook;
using lab8::KindleBook;
using lab8::Library;

static std::vector<std::string> two_pages = {
    "page 1", "page 2"
};
static std::vector<std::string> three_pages = {
    "page 1", "page 2", "page 3"
};

void test_library_bookcount() {
    Library lib;
    assert(lib.bookcount() == 0);

    auto pb = std::make_unique<FullTextBook>("Old Man and the Sea", "Hemingway", two_pages);
    lib.add_book(std::move(pb));
    assert(lib.bookcount() == 1);

    lib.add_book(std::make_unique<KindleBook>("A Rebours", "Huysmans"));
    assert(lib.bookcount() == 2);

    lib.add_book(std::make_unique<FullTextBook>("A Rebours", "Huysmans", three_pages));
    assert(lib.bookcount() == 3);
}

void test_library_pagecount() {
    Library lib;
    assert(lib.pagecount() == 0);

    auto pb = std::make_unique<FullTextBook>("Old Man and the Sea", "Hemingway", two_pages);
    lib.add_book(std::move(pb));
    assert(lib.pagecount() == 2);

    lib.add_book(std::make_unique<KindleBook>("A Rebours", "Huysmans"));
    assert(lib.pagecount() == 2);

    lib.add_book(std::make_unique<FullTextBook>("A Rebours", "Huysmans", three_pages));
    assert(lib.pagecount() == 5);
}

void test_library_removebooks_by_title() {
    Library lib;
    lib.add_book(std::make_unique<KindleBook>("Old Man and the Sea", "Hemingway"));
    lib.add_book(std::make_unique<KindleBook>("A Rebours", "Huysmans"));
    lib.add_book(std::make_unique<KindleBook>("I Am a Strange Loop", "Hofstadter"));
    lib.add_book(std::make_unique<KindleBook>("Death in the Afternoon", "Hemingway"));
    lib.add_book(std::make_unique<KindleBook>("A Farewell to Arms", "Hemingway"));
    lib.remove_books_by_title("A Farewell to Arms");
    assert(lib.bookcount() == 4);
    lib.remove_books_by_title("Catch-22");  // should not be found
    assert(lib.bookcount() == 4);
    lib.remove_books_by_title("A Rebours");
    assert(lib.bookcount() == 3);
}

void test_library_removebooks_by_author() {
    Library lib;
    lib.add_book(std::make_unique<KindleBook>("Old Man and the Sea", "Hemingway"));
    lib.add_book(std::make_unique<KindleBook>("A Rebours", "Huysmans"));
    lib.add_book(std::make_unique<KindleBook>("I Am a Strange Loop", "Hofstadter"));
    lib.add_book(std::make_unique<KindleBook>("Death in the Afternoon", "Hemingway"));
    lib.add_book(std::make_unique<KindleBook>("A Farewell to Arms", "Hemingway"));
    lib.remove_books_by_author("Hemingway");
    assert(lib.bookcount() == 2);
    lib.remove_books_by_author("Hemingway");
    assert(lib.bookcount() == 2);
}
