WFLAGS	= -Wall -Werror -pedantic
DEBUGFLAGS = -g
TESTFLAGS = -L/usr/lib32 
CFLAGS	= -I include -m32 -ansi $(WFLAGS) $(DEBUGFLAGS) # $(TESTFLAGS)
CC	= g++
DEPS	= MyMathLib.hpp EulerProblem.hpp
SOLVED	= $(patsubst p%.cpp,p%.o,$(wildcard p*.cpp))

EulerProblems:	main.o FileLib.o MyMathLib.o BigInt.o BigIntTests.o EulerProblem.o $(SOLVED) 
	$(CC) $(CFLAGS) $^ -o $@

main.o:	main.cpp BigInt.cpp $(wildcard p*.cpp) 	
	$(CC) $(CFLAGS) $^ -c

BigInt.o: BigInt.cpp BigInt.hpp $(DEPS)
	$(CC) $(CFLAGS) $^ -c

BigIntTests.o: BigInt.cpp BigIntTests.cpp 
	$(CC) $(CFLAGS) $^ -c

p/%.o: p/%.cpp p/%.hpp $(DEPS)
	$(CC) $^ -c $@ $(CFLAGS)

%.o: %.cpp 
	$(CC) $(CFLAGS) $^ -c

clean:
	rm -f *.o
