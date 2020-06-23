CXXFLAGS= -std=c++14 -O2 -W -Wall -Wextra -pedantic
OBJFILES= book.o fulltextbook.o kindlebook.o library.o fulltextbook.t.o kindlebook.t.o library.t.o tests.m.o

test: tests
	./tests

tests: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fulltextbook.o: fulltextbook.cpp fulltextbook.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fulltextbook.t.o: fulltextbook.t.cpp fulltextbook.t.hpp fulltextbook.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

kindlebook.o: kindlebook.cpp kindlebook.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

kindlebook.t.o: kindlebook.t.cpp kindlebook.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

library.t.o: library.t.cpp library.hpp fulltextbook.hpp kindlebook.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES) tests

.PHONY: clean
