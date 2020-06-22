## Lab 4: operator<<

In this mini lab, you'll write an overloaded stream-insertion operator.
It should take you only about 15 minutes.

Your code should make proper use of

    - everything from Lab 3, plus

    - overloading operator<<

All your code should be in the `lab4` namespace.

### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

First, run `make` to build the whole project. The compiler will try to compile `tests.m.cpp`
and complain that it found no overload of `operator<<` callable with a `Book`.
On my machine, this triggers a 300-line cascade of error messages. Remember to
look at the first error message, not the last one!

    book.t.cpp:31:13: error: invalid operands to binary expression ('std::ostringstream' (aka 'basic_ostringstream<char>') and 'lab4::Book')
            oss << b;
            ~~~ ^  ~

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

Add a stream-insertion operator to `Book`.

Your overloaded `operator<<` should print the book in the exact format
`"TITLE by AUTHOR (XXX pages)"`.  That is,

    Book b("Die Harzreise", "Heine", 80);
    std::cout << b << '\n';

should print "Die Harzreise by Heine (80 pages)" followed by a newline.

## Testing

The file tests.m.cpp contains _unit tests_ for this lab. Your code should pass
all the provided tests. Consider writing additional unit tests.

#### A note on source code organization

I'm using a convention that I originally saw at Bloomberg.
"foo.hpp" and "foo.cpp" implement the foo functionality.
"foo.t.cpp" holds the _unit tests_ for the foo functionality.
"foo.m.cpp" (if present) holds the `main()` routine for the foo program.
In these labs, the only `main()` routine is in "tests.m.cpp".

## Bonus

There are several ways to solve this lab. My preferred way goes like this.
If you originally solved the lab another way, try it this way as well:

- Implement a member function `void Book::print(std::ostream&) const`.

- Use the hidden friend idiom to implement `operator<<` as a non-member
    function within the body of `class Book`. Its body should be two lines:
    `this->print(os)` and `return os`.

Learning this approach today will help you with Lab 8 tomorrow.

This is similar to the "Façade" pattern: we must write an `operator<<`
with a particular interface for historical reasons, but we can make it
internally dispatch to a named implementation method with a simpler API.

Look at the test code, and then add another member function
with the signature `std::string Book::to_string() const`,
also implemented in terms of `print`.
