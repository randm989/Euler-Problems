WFLAGS	= -Wall -Werror -pedantic
TESTFLAGS = -L/usr/lib32 
CFLAGS	= -I include -m32 -ansi $(TESTFLAGS) $(WFLAGS) 
CC	= g++
DEPS	= MyMathLib.hpp EulerProblem.hpp
SOLVED	= $(patsubst p%.cpp,p%.o,$(wildcard p*.cpp))

EulerProblems:	main.o MyMathLib.o BigInt.o $(SOLVED)
	$(CC) $(CFLAGS) $^ -o $@

main.o:	main.cpp BigInt.cpp $(wildcard p*.cpp) 	
	$(CC) $(CFLAGS) $^ -c

BigInt.o: BigInt.cpp BigInt.hpp $(DEPS)
	$(CC) $(CFLAGS) $^ -c

MyMathLib.o: MyMathLib.cpp 
	$(CC) $(CFLAGS) $^ -c

p/%.o: p/%.cpp p/%.hpp $(DEPS)
	$(CC) $^ -c $@ $(CFLAGS)


clean:
	rm -f *.o
