CC = clang
TARGET	= main
FLAGS	= -Wall -pedantic -std=c99
HEADERS = src/lib.c

$(TARGET).out: src/$(TARGET).c
	$(CC) src/$(TARGET).c $(FLAGS) $(HEADERS) -o target/$(TARGET).out

run: $(TARGET).out
	./target/$(TARGET).out $(USER)	

test.out: test/test.c
	$(CC) test/test.c $(HEADERS) -o target/test.out

test: test.out
	./target/test.out

clear:
	rm -f target/*.out
	clear && ls
