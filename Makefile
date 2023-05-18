main: main.o Node.o OList.o Person.o Dictionary.o
	g++ -o main main.o Node.o OList.o Person.o Dictionary.o

tests: tests.o Node.o OList.o Person.o Dictionary.o
	g++ -o tests tests.o Node.o OList.o Person.o Dictionary.o

main.o: main.cpp Node.h OList.h Person.h Dictionary.h

OList.o: OList.cpp Node.h Person.h

Node.o: Node.cpp Node.h

tests.o: tests.cpp OList.h Person.h Node.h doctest.h

clean:
	rm -f main main.o tests.o Node.o OList.o Person.o Dictionary.o
