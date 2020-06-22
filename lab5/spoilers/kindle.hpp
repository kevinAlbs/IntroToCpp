#ifndef INCLUDED_KINDLE_HPP
#define INCLUDED_KINDLE_HPP

#include "book.hpp"
#include "library.hpp"

namespace lab5 {

Book convert_to_kindle(const Book&);
Library convert_to_kindle(const Library&);

template <class T>
bool would_benefit_from_kindle(const T& object) {
    return object.pagecount() > 0;
}

}  // namespace lab5

#endif  // INCLUDED_KINDLE_HPP
