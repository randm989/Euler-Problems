WFLAGS	= -Wall -Werror -pedantic
CFLAGS	= -I include -ansi -m64 $(WFLAGS)
CC	= g++
DEPS	= EulerProblem.hpp
SOLVED	= p1.o p2.o p3.o p4.o p5.o p6.o p7.o p8.o

EulerProblems:	main.o BigInt.o	$(SOLVED)
	$(CC) $(CFLAGS) $^ -o $@

main.o:	main.cpp BigInt.cpp $(wildcard p*.cpp) 	
	$(CC) $(CFLAGS) $^ -c

BigInt.o: BigInt.cpp BigInt.hpp $(DEPS)
	$(CC) $(CFLAGS) $^ -c

p/%.o: p/%.cpp p/%.hpp $(DEPS)
	$(CC) $^ -c $@ $(CFLAGS)


clean:
	rm *.o
	rm EulerProblems
