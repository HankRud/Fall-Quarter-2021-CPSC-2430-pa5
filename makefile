pa5: pa5.o hash.o movie.o
	g++ pa5.cpp hash.h hash.cpp movie.h movie.cpp -o pa5
clean:
	rm.*o