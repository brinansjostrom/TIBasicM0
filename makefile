OBJECTS = main.o parser.o
CFLAGS = -Wall -g -c -Iinclude
CC = gcc
EXE = build/TIBasicM0
TEST_BUILDS = tests/test_validator.out

#Compile all
default: all
all: $(OBJECTS) 
	$(CC) -o $(EXE) $(OBJECTS)

main.o: src/main.c
	$(CC) $(CFLAGS) -o main.o src/main.c


parser.o: src/parser.c
	$(CC) $(CFLAGS) -o parser.o src/parser.c

clean:
	rm *.o $(OBJECTS) $(EXE) $(TEST_BUILDS)

# test cases
# Test Parser src
test_parser: parser.o test_parser.o
	$(CC) parser.o test_parser.o -o tests/test_parser.out

parser.o: src/parser.c
	$(CC) $(CFLAGS) -o parser.o src/parser.c

test_parser.o: tests/test_parser.c
	$(CC) $(CFLAGS) -o test_parser.o tests/test_parser.c
