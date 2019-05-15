## Lab 1: Palindromes

In this lab, you'll write two functions that manipulate strings.

Your code should make proper use of

    - function declarations and definitions

    - header files and source files

    - namespaces

    - pass-by-reference and pass-by-value

    - the `const` qualifier

### Getting started

A partial solution (missing only `lab1.hpp` and `lab1.cpp`) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab1.m.cpp`
and immediately complain that the header file `lab1.hpp` was included but
does not yet exist. Study the code to see what `lab1.hpp` ought to declare.

You will write two new functions, declared in `lab1.hpp` and defined in
`lab1.cpp`:

    - `lab1::reverse_in_place(s)` reverses the string `s` in place.

    - `lab1::is_palindrome(s)` returns a `bool` (`true` or `false`)
      depending on whether the given string is a palindrome or not.
      This function does not modify the string that was passed in,
      although it might make a copy of it.
