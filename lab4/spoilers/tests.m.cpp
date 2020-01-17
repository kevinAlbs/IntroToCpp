#include "book.t.hpp"
#ifndef SKIP_PART2
#include "library.t.hpp"
#endif
#ifndef SKIP_PART3
#include "kindle.t.hpp"
#endif

#include <cstdio>

int main() {
#ifndef SKIP_PART1
    test_book_getters();
    test_book_const_getters();
    test_book_stream_insertion();
    test_book_stream_insertion_chaining();
#endif

#ifndef SKIP_PART2
    test_library_addbook();
    test_library_removebooks_by_author();
    test_library_removebooks_by_title();
    test_library_iteration();
    test_library_const_iteration();
#endif

#ifndef SKIP_PART3
    test_kindle_book_template();
    test_kindle_library_template();
#endif

    std::puts("If you're seeing this line, it means all tests passed.");
}
