OBJECTS = build/main.o build/validator.o
CFLAGS = -Wall -g -c -Iinclude
CC = gcc
EXE = build/TIBasicM0
TEST_BUILDS = tests/test_validator.out

#Compile all
default: all
all: $(OBJECTS) 
	$(CC) -o $(EXE) $(OBJECTS)

build/main.o: src/main.c
	$(CC) $(CFLAGS) -o build/main.o src/main.c


build/validator.o: src/validator.c
	$(CC) $(CFLAGS) -o build/validator.o src/validator.c

clean:
	rm *.o $(OBJECTS) $(EXE) $(TEST_BUILDS)

# test cases
# Test Validator src
test_validator: validator.o test_validator.o
	$(CC) validator.o test_validator.o -o tests/test_validator.out

validator.o: src/validator.c
	$(CC) $(CFLAGS) -o validator.o src/validator.c

test_validator.o: tests/test_validator.c
	$(CC) $(CFLAGS) -o test_validator.o tests/test_validator.c
