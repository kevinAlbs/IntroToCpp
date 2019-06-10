## Lab 4: Library

In this lab, you'll re-implement parts of Book and Library,
and test your skills with function overloading and function templates.
It should take you about 90 minutes.

Your code should make proper use of

    - everything from Lab 3, plus

    - function templates

    - function overloading

    - overloading operator<<

    - basic use of iterators and STL algorithms

All your code should be in the `lab4` namespace.

### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

#### This lab has multiple parts

This lab has multiple parts. You can unit-test the parts individually
with `make p1`, `make p2`, `make p3`; or just `make` to build all of the
tests together.

First, run `make` to build the whole project. The compiler will try to compile `tests.m.cpp`
and immediately complain that the header file `kindle.t.hpp` was included but
does not yet exist.

Now, run `make p1` to build just Part 1. The compiler will try to compile `tests.m.cpp`
and complain that it found no overload of `operator<<` callable with a `Book`.
On my machine, this triggers a 300-line cascade of error messages. Remember to
look at the first error message, not the last one!

    book.t.cpp:31:13: error: invalid operands to binary expression ('std::ostringstream' (aka 'basic_ostringstream<char>') and 'lab4::Book')
            oss << b;
            ~~~ ^  ~

#### A note on source code organization

I'm using a convention that I originally saw at Bloomberg.
"foo.hpp" and "foo.cpp" implement the foo functionality.
"foo.t.cpp" holds the _unit tests_ for the foo functionality.
"foo.m.cpp" (if present) holds the `main()` routine for the foo program.
In these labs, the only `main()` routine is in "tests.m.cpp".

## 1. Add a stream-insertion operator to `Book`

Class `Book` has the following member functions, most of which
are the same as in Lab 3:

| Name                           | Purpose                    |
| :----------------------------- | :------------------------- |
| Book(title, author, pagecount) | Constructor                |
| title()                        | Get the title of the book  |
| author()                       | Get the author of the book |
| pagecount()                    | Get the number of pages    |
| swap(rhs : Book)               | Exchange the contents of this book object with another |
| `operator<<`                   | Print the book to an ostream |

Your overloaded `operator<<` should print the book in the exact format
`"TITLE by AUTHOR (XXX pages)"`.  That is,

    Book b("Die Harzreise", "Heine", 80);
    std::cout << b << '\n';

should print "Die Harzreise by Heine (80 pages)" followed by a newline.

## 2. Make `Library` use more iterators

- 2a. Make `Library` an iterable range of `Book`s.

- 2b. Use more STL algorithms in `Library`.

Class `Library` has the following member functions, most of which
are the same as in Lab 3:

| Name                           | Purpose                    |
| :----------------------------- | :------------------------- |
| Library()                      | Constructor                |
| add_book(Book)                 | Add a book to the library  |
| bookcount()                    | Return the number of books in the library |
| pagecount()                    | Return the total number of pages in the library |
| remove_books_by_title(title)   | Remove all books in the library with the given title |
| remove_books_by_author(author) | Remove all books in the library with the given author |
| begin()                        | Return an iterator to the first book in the library |
| end()                          | Return an iterator one past the last book in the library |

Your `Library` will probably have a private data member `books_`
of type `std::vector<Book>`.

For `begin()` and `end()`, you should follow our guidelines for const-correct code.
Should I be able to iterate over the books in a `const Library`?
Should I be able to modify the books in a non-const `Library`?

For the complicated functions such as `pagecount` and `remove_books_by_title`,
you should *not* cut and paste your code from Lab 3. Instead, you should reimplement
those functions from scratch, using STL algorithms such as `std::accumulate`
and `std::remove_if`.

Use the erase-remove idiom in `remove_books_by_title` and `remove_books_by_author`.


## 3. Implement `kindle` functionality

If you've done the bonus to Lab 3, you're one-third of the way done with this part!

### 3a. `convert_to_kindle` function overload set

In "kindle.hpp" and "kindle.cpp", implement a function overload set `convert_to_kindle`.
When called on a `Book`, `convert_to_kindle` should return a new `Book` that's equivalent
except that its page count is zero.

    Book b("Old Man and the Sea", "Hemingway", 100);
    Book k = convert_to_kindle(b);
    assert(k.title() == "Old Man and the Sea");
    assert(k.author() == "Hemingway");
    assert(k.pagecount() == 0);

When called on a `Library`, `convert_to_kindle` should return a new `Library` that
contains the same number of `Book`s, all individually converted to kindle.

    Library lib;
    lib.add_book(Book("Old Man and the Sea", "Hemingway", 100));
    Library k = convert_to_kindle(lib);
    assert(k.bookcount() == 1);
    assert(k.pagecount() == 0);


### 3b. `would_benefit_from_kindle` function template

In "kindle.hpp", implement a function template `would_benefit_from_kindle`.
When called on any object with a `.pagecount()` method, this function should
return `true` if and only if the object's page count is greater than zero.

    Library lib;
    Book book("Old Man and the Sea", "Hemingway", 100);
    assert(would_benefit_from_kindle(book));
    assert(!would_benefit_from_kindle(convert_to_kindle(book)));
    lib.add_book(book);
    assert(would_benefit_from_kindle(lib));
    assert(!would_benefit_from_kindle(convert_to_kindle(lib)));


## Testing

The file tests.m.cpp contains _unit tests_ for this lab. Your code should pass
all the provided tests. Consider writing additional unit tests.

## Bonus

If you have time, implement a member function template `Library::remove_books_if(Pred)`
that takes any arbitrary predicate (e.g. as a lambda) and removes books that match
the predicate.

Then, reimplement `remove_books_by_author` and `remove_books_by_title` as one-liners
that simply call `remove_books_if` with different predicates.

Consider whether `remove_books_if` should be part of your `Library`'s public API.
