## Lab 7: Associative containers

In this lab, you'll re-implement parts of Book and Library
using associative containers.
It should take you about an hour.

Your code should make proper use of

    - everything from Lab 5, plus

    - associative STL containers

    - custom comparators

All your code should be in the `lab7` namespace.

### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. `make` will complain that there is no way
to build `library.o` because `library.cpp` does not exist.


## Implement an efficient `remove_books_by_author`

We've received an updated priority from our customer
(Stoneman & Black LLC).
They anticipate needing to quickly remove all books by
a single author. Removing books by title is a less common
operation and they don't mind if it takes relatively longer.

Modify your class `Library` to store `Book` objects in
a `std::multiset` rather than a `std::vector<Book>`.
The required member functions remain the same:

| Name                           | Purpose                    |
| :----------------------------- | :------------------------- |
| Library()                      | Constructor                |
| add_book(Book)                 | Add a book to the library  |
| bookcount()                    | Return the number of books in the library |
| pagecount()                    | Return the total number of pages in the library |
| remove_books_by_title(title)   | Remove all books in the library with the given title |
| remove_books_by_author(author) | Efficiently remove all books in the library with the given author |

You should instantiate `std::multiset` with a custom comparator which compares
only `book.author()`. Finding all books by a single author should now be 
achievable in O(lg n) time.

In `remove_books_by_title`, it is acceptable to use an O(n) algorithm.
As explained in lecture, you _cannot_ use the erase-remove idiom on a 
`std::multiset`; you will have to use the `erase` method of `std::multiset`
in a loop.

Consider writing a helper function (or function template) named `erase_if`.


## Testing

The file tests.m.cpp contains _unit tests_ for this lab. Your code should pass
all the provided tests. Consider writing additional unit tests.


## Bonus

Think about how you might permit the client to _change_ the author of a book
in the library.

Think about how you might speed up `remove_books_by_title` without slowing down
`remove_books_by_author`.

The problem of doing lookups by two different keys is addressed by
special-purpose data structure libraries such as
[Boost.MultiIndex](https://theboostcpplibraries.com/boost.multiindex).
