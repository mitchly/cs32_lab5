CXX=clang++
CXXFLAGS=-std=c++17 -Wall

BINARIES=lab5test

all: ${BINARIES}

lab5test: lab5test.o tddFuncs.o WordCount.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./lab5test

clean:
	/bin/rm -f ${BINARIES} *.o