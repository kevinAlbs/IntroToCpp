## Lab 1: Palindromes

In this lab, you'll write two functions that manipulate strings.

Your code should make proper use of

    - function definitions

    - `for` loops

    - pass-by-reference and pass-by-value

    - the `const` qualifier

### Getting started

A partial solution (missing only some lines from the middle) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab1.m.cpp`
and immediately complain that the identifier `is_palindrome` was never declared.
does not yet exist. Study the code to see what functions you need to add.

You will write two new functions, defined in `lab1.m.cpp`:

    - `reverse_in_place(&s)` reverses the string `s` in place.
      Since it modifies its parameter, we're going to use pass-by-pointer.

    - `is_palindrome(s)` returns a `bool` (`true` or `false`)
      depending on whether the given string is a palindrome or not.
      This function does not modify the string that was passed in,
      although it might make a copy of it.
