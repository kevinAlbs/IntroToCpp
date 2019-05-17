## Lab 5: Move semantics

In this lab, you'll add move semantics to Book and Library.
It should take you about 30 minutes.

Your code should make proper use of

    - everything from Lab 4, plus

    - rvalue references and `std::move`

All your code should be in the `lab5` namespace.

### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. The compiler will try to compile `tests.m.cpp`
and immediately complain that the header file `library.cpp` was included but
does not yet exist.


## 1. Use move semantics in the constructor of `Book`

In the spoiler solution for Lab 4, running

    Book catch22("Catch-22", "Heller", 544);

will construct `std::string("Catch-22")` and pass that temporary
by const reference to the constructor of `Book`, which will copy-construct
`title_` from that temporary. This means two heap allocations when we
could have used only one.

Rewrite the constructor of `Book` to perform fewer heap allocations
in this case.

There are at least three ways to approach this task:

- Replace the existing constructor's `const std::string&` parameters with `std::string` parameters,
  and then `std::move` those string parameters into your member initializers.
  This is the simplest and most practically relevant approach.

- Add constructors taking `std::string&&`, in addition to the constructors taking `const std::string&`.
  This approach is less simple, but will better exercise your understanding of rvalue references.

- Replace the existing constructor with a _constructor template_ that can accept either `string` or `const char *` directly.
  You are not expected to be able to do this correctly. It is also unlikely to be a good idea in practice.


## 2. Use move semantics in `Library::add_book`

Replace Lab 4's `Library::add_book(const Book&)` with either
`Library::add_book(Book)` or `Library::add_book(Book&&)`.

Be prepared to explain why you chose the implementation you did.


## Testing

The file tests.m.cpp contains _unit tests_ for this lab. Your code should pass
all the provided tests.

In this particular lab, the partial solution in `partial/` will actually build
successfully. That's because move semantics is a pure optimization: the observable
behavior of the code should remain the same after your changes, but the performance
of the code (as measured in heap allocations and deallocations) should improve.

The unit tests use an obscure feature of C++ (out of scope for this course)
to hook into `new` and `delete` and verify that your constructor for `Book`
does not perform unnecessary allocations. You are not expected to understand
operator-new.t.cpp, and you are specifically expected _not_ to write code
like it in production!


## Bonus

Rewrite `convert_to_kindle` in move-semantic style.

Rewrite `would_benefit_from_kindle` in move-semantic style.
(Is any change needed? Why or why not?)

Observe that when you construct `std::string("Catch-22")`, the
runtime doesn't do a heap allocation, but when you construct
`std::string("The Curious Incident of the Dog in the Night-Time")`,
it does. What's the deal with that?
