// You should not modify this file.

#include "operator-new.t.hpp"

#include <cstdlib>
#include <new>

void* operator new(size_t bytes) {
    new_called() = true;
    new_count() += 1;
    return std::malloc(bytes);
}

void operator delete(void* p, size_t) noexcept {
    std::free(p);
}
