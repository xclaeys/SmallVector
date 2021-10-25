
test: test.o
	g++ test.o -o test

test.o:
	g++ -c test.cpp -o test.o

check:
	./test

clean:
	rm *.o
