.PHONY: all test

all: bin/alphabet bin/test

clean:
	rm -rf bin/alphabet bin/test *.o

test:
	./bin/test

build/test/test.o: test/test.cpp
	g++ -std=c++17 -Wall -Werror -c -o build/test/test.o test/test.cpp

build/test/test_functions.o: test/test_functions.cpp
	g++ -std=c++17 -Wall -Werror -c -o build/test/test_functions.o test/test_functions.cpp

build/src/main.o: src/main.cpp
	g++ -std=c++17 -Wall -Werror -c -o build/src/main.o src/main.cpp

build/src/functions.o: src/functions.cpp
	g++ -std=c++17 -Wall -Werror -c -o build/src/functions.o src/functions.cpp

bin/test: build/test/test.o build/src/functions.o build/test/test_functions.o
	g++ -o bin/test build/test/test.o build/src/functions.o build/test/test_functions.o

bin/alphabet: build/src/main.o build/src/functions.o
	g++ -o bin/alphabet build/src/main.o build/src/functions.o
