#!make -f
#id:322530080 mail:avishb1213@gmail.com
CXX=g++
CXXFLAGS=-std=c++11 -g  -Wall  
VALGRIND_FLAGS=-v  --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SD=Graph.cpp Algorithms.cpp 
ST=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OD=$(subst .cpp,.o,$(SD))
OT=$(subst .cpp,.o,$(ST))

.PHONY: all run demo test tidy valgrind clean

all: demo test

run: demo
	./$^

demo: Demo.o $(OD)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OT)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	g++-tidy $(st) -checks=bugprone-*,g++-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test