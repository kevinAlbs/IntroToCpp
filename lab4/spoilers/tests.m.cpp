#include "book.t.hpp"

#include <cstdio>

int main() {
    test_book_getters();
    test_book_const_getters();
    test_book_stream_insertion();
    test_book_stream_insertion_chaining();

    std::puts("If you're seeing this line, it means all tests passed.");
}
