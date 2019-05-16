
#include "kindle.hpp"
#include "book.hpp"
#include "library.hpp"
#include <algorithm>

namespace lab4 {

Book convert_to_kindle(const Book& b)
{
    return Book(b.title(), b.author(), 0);
}

Library convert_to_kindle(const Library& lib)
{
    Library result;
    std::for_each(
        lib.begin(),
        lib.end(),
        [&](const Book& book) {
            result.add_book(convert_to_kindle(book));
        }
    );
    return result;
}

} // namespace lab4
