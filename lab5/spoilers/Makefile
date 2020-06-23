CXXFLAGS= -std=c++14 -O2 -W -Wall -Wextra -pedantic
OBJFILES= book.o kindle.o library.o book.t.o kindle.t.o library.t.o tests.m.o

test: tests
	./tests

tests: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

book.t.o: book.t.cpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

kindle.o: kindle.cpp kindle.hpp library.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

kindle.t.o: kindle.t.cpp kindle.hpp library.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

library.o: library.cpp library.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

library.t.o: library.t.cpp library.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

p1:
	$(CXX) $(CXXFLAGS) -DSKIP_PART2 book.cpp library.cpp book.t.cpp library.t.cpp tests.m.cpp -o tests
	./tests

p2:
	$(CXX) $(CXXFLAGS) -DSKIP_PART1 book.cpp library.cpp kindle.cpp book.t.cpp kindle.t.cpp tests.m.cpp -o tests
	./tests

clean:
	rm -f $(OBJFILES) tests

.PHONY: clean p1 p2 test
