## Lab 3: Library

In this lab, you'll write classes for Book and Library.
It should take you about an hour.

Your code should make proper use of

    - everything from Lab 2, plus

    - class definitions

    - constructors

    - const member functions

### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. The compiler will try to compile `tests.m.cpp`
and immediately complain that the header file `book.hpp` was included but
does not yet exist.


## Class `Book`

Class `Book` has the following member functions:

| Book(title, author, pagecount) | Constructor |
| title()                        | Get the title of the book |
| author()                       | Get the author of the book |
| pagecount()                    | Get the number of pages |
| swap(rhs : Book)               | Exchange the contents of this book object with another |


## Class `Library`

Class `Library` has the following member functions:

| Library()                      | Constructor |
| add_book(Book)                 | Add a book to the library |
| bookcount()                    | Return the number of books in the library |
| pagecount()                    | Return the total number of pages in the library |
| remove_books_by_title(title)   | Remove all books in the library with the given title |
| remove_books_by_author(author) | Remove all books in the library with the given author |

Your `Library` will probably have a private data member `books_`
of type `std::vector<Book>`.


## Testing

The file tests.m.cpp contains _unit tests_ for this lab. Your code should pass
all the provided tests. Consider writing some additional unit tests.

## Bonus

If you have time, add a function `kindle_edition_of`
that takes a `Book` and returns a `Book` that's equivalent
except that its page count is zero.

    Book b("Old Man and the Sea", "Hemingway", 100);
    Book k = kindle_edition_of(b);
    assert(k.title() == "Old Man and the Sea");
    assert(k.author() == "Hemingway");
    assert(k.pagecount() == 0);
