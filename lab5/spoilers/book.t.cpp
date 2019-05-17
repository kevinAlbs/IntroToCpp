#include "book.t.hpp"
#include "book.hpp"
#include "operator-new.t.hpp"

#include <cassert>
#include <cstdio>
#include <string>
#include <sstream>

using lab5::Book;

void test_book_getters()
{
    Book b("The Curious Incident of the Dog in the Night-Time", "Haddon", 226);
    assert(b.title() == "The Curious Incident of the Dog in the Night-Time");
    assert(b.author() == "Haddon");
    assert(b.pagecount() == 226);
}

void test_book_const_getters()
{
    const Book c("A Rebours", "Huysmans", 400);
    assert(c.title() == "A Rebours");
    assert(c.author() == "Huysmans");
    assert(c.pagecount() == 400);
}

void test_book_stream_insertion()
{
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

void test_book_stream_insertion_chaining()
{
    Book b("The Scarlet Letter", "Hawthorne", 200);
    std::ostringstream oss;
    oss << '.' << b << ".\n";
    std::string representation = oss.str();
    assert(representation == ".The Scarlet Letter by Hawthorne (200 pages).\n");
}

void test_book_move_semantics()
{
    new_called() = false;
    std::string title = "The Curious Incident of the Dog in the Night-Time";
    assert(new_called());
    std::string author = "Haddon";

    new_called() = false;
    Book b(std::move(title), std::move(author), 226);
    if (new_called()) {
        std::puts("WARNING: an unnecessary heap allocation was made in Book's constructor!");
    }

    assert(b.title() == "The Curious Incident of the Dog in the Night-Time");
}

