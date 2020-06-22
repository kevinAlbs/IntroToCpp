#include "fulltextbook.t.hpp"
#include "kindlebook.t.hpp"
#include "library.t.hpp"

#include <cstdio>

int main() {
    test_kindlebook_getters();
    test_kindlebook_const_getters();
    test_kindlebook_stream_insertion();
    test_kindlebook_stream_insertion_chaining();

    test_fulltextbook_getters();
    test_fulltextbook_const_getters();
    test_fulltextbook_stream_insertion();
    test_fulltextbook_stream_insertion_chaining();
    test_fulltextbook_get_page();
    test_fulltextbook_virtual_destructor();

    test_library_bookcount();
    test_library_pagecount();
    test_library_removebooks_by_author();
    test_library_removebooks_by_title();

    std::puts("If you're seeing this line, it means all tests passed.");
}
