## Lab 8: Polymorphic Book

In this lab, you'll re-implement parts of Book and Library,
and test your skills with function overloading and function templates.
It should take you about 90 minutes.

Your code should make proper use of

    - everything from Lab 4, plus

    - inheritance

    - virtual functions and destructors

    - unique_ptr

All your code should be in the `lab8` namespace.

### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. The compiler will try to compile `tests.m.cpp`
and immediately complain that it cannot make `book.o` because `book.cpp` does not
yet exist.


## 1. Rewrite `Book` to be a polymorphic base class

Every book is guaranteed to have a title and an author.

However, in this lab, different kinds of books have different
behaviors when asked for their page count or when asked to
print themselves.

Class `Book` has the following member functions:

| Name                           | Purpose                    |
| :----------------------------- | :------------------------- |
| Book(title, author)            | Protected constructor      |
| title()                        | Get the title of the book  |
| author()                       | Get the author of the book |
| pagecount()                    | Get the number of pages    |
| swap(rhs : Book)               | This function should no longer be provided |
| print(os : ostream)            | Print the book and its type to `os` |

`print` and `pagecount` should either be pure virtual methods; or,
using the Non-Virtual Interface pattern, should be non-virtual methods that
rely on pure virtual methods for part of their functionality.

You should provide a non-member `operator<<` that dispatches to `Book::print`.

`title` and `author` should _not_ be pure virtual methods; they should have
behavior which is common to all kinds of `Book`s.


## 2. Make `Library` use smart pointers

Class `Library` has the following member functions, most of which
are the same as in Lab 3:

| Name                           | Purpose                    |
| :----------------------------- | :------------------------- |
| Library()                      | Constructor                |
| add_book(unique_ptr\<Book>)    | Add a book to the library  |
| bookcount()                    | Return the number of books in the library |
| pagecount()                    | Return the total number of pages in the library |
| remove_books_by_title(title)   | Remove all books in the library with the given title |
| remove_books_by_author(author) | Remove all books in the library with the given author |

Your `Library` should have a private data member `books_`
of type `std::vector<std::unique_ptr<Book>>`.

For this lab, your `Library` does not need to model an iterable range of `Book`s.
The `begin` and `end` methods have been removed from the specification.


## 3. Add two concrete derived classes of `Book`

### 3a. Implement class `FullTextBook` as a subclass of `Book`

A `FullTextBook` has additional methods

| Name                                                           | Purpose            |
| :------------------------------------------------------------- | :----------------- |
| FullTextBook(title, author, pages : std::vector\<std::string>) | Public constructor |
| get_page(n : int)                                              | Get the text of the given page, as a string |
| pagecount()                                                    | Overrides `Book::pagecount()` |

The `pagecount` method of a `FullTextBook` should return `pages_.size()`.

The `get_page` method should return `pages_[n]`.

When you use `operator<<` on a `FullTextBook`, it should print a string
that looks like this:

    TITLE by AUTHOR (XX pages, full text)

Since a `FullTextBook` IS-A `Book`, you should not implement a new `operator<<`
specifically for `FullTextBook`; you should merely implement an overriding
`print` method which will be called by your existing `operator<<`.


### 3b. Implement class `KindleBook` as a subclass of `Book`

| Name                       | Purpose            |
| :------------------------- | :----------------- |
| KindleBook(title, author)  | Public constructor |
| pagecount()                | Overrides `Book::pagecount()` and invariably returns zero |

When you use `operator<<` on a `KindleBook`, it should print a string
that looks like this:

    TITLE by AUTHOR (0 pages, Kindle)


## Testing

The file tests.m.cpp contains _unit tests_ for this lab. Your code should pass
all the provided tests. Consider writing additional unit tests.

If you get strange runtime errors during testing, run `make clean` and then `make` again
before asking for help. Sometimes it's just an object file that didn't get rebuilt
when it should have been.


## Bonus

1. If you have time, modify your `FullTextBook::get_page(int)` member function
so that it bounds-checks the page number and throws an exception of type `std::out_of_range`
when the page number is out of range. Write a unit test to verify this behavior.

2. If you have time, implement a member function `Library::lettercount()` that iterates
over all the books in a library and counts all the letters in every `FullTextBook`
(skipping `KindleBook`s because their text is not available).

This function will have to use `dynamic_cast`, or else you'll have to add a method
such as `get_page_if_possible(int)` to the virtual API of `Book`. What approach would
you rather take, and why?
