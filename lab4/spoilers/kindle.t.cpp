#include "book.hpp"
#include "kindle.hpp"
#include "library.hpp"

#include <cassert>

using lab4::Book;
using lab4::Library;
using lab4::would_benefit_from_kindle;
using lab4::convert_to_kindle;

void test_kindle_book_template()
{
    auto book = Book("Old Man and the Sea", "Hemingway", 100);
    assert(would_benefit_from_kindle(book));

    Book kbook = convert_to_kindle(book);
    assert(kbook.pagecount() == 0);
    assert(!would_benefit_from_kindle(kbook));
}

void test_kindle_library_template()
{
    Library lib;
    assert(!would_benefit_from_kindle(lib));

    lib.add_book(Book("Old Man and the Sea", "Hemingway", 100));
    assert(lib.bookcount() == 1);
    assert(would_benefit_from_kindle(lib));

    Library klib = convert_to_kindle(lib);
    assert(klib.bookcount() == 1);
    assert(!would_benefit_from_kindle(klib));
    for (const Book& book : klib) {
        assert(!would_benefit_from_kindle(book));
    }
}
