CC= gcc
CFLAGS = -g -Wall -std=c99

all: test 

test:	
	$(CC) hash_matrix.c test_hash_matrix.c -o test -pthread $(CFLAGS)

clean:
	rm -rf test
