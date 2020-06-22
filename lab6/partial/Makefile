CXXFLAGS= -std=c++14 -O1 -W -Wall -Wextra -pedantic
OBJFILES= book.o library.o book.t.o library.t.o operator-new.t.o tests.m.o

test: tests
	./tests

tests: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES) tests

.PHONY: clean
