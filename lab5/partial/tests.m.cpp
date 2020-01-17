#include "book.t.hpp"
#include "library.t.hpp"
#include "operator-new.t.hpp"

#include <cstdio>

int main() {
    test_book_getters();
    test_book_const_getters();
    test_book_stream_insertion();
    test_book_stream_insertion_chaining();
    test_book_move_semantics();

    test_library_addbook();
    test_library_removebooks_by_author();
    test_library_removebooks_by_title();
    test_library_iteration();
    test_library_const_iteration();

    std::puts("If you're seeing this line, it means all tests passed.");
    std::printf("A total of %zu heap allocations were made by all tests.\n", new_count());
}
