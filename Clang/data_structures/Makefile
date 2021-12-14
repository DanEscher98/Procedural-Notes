CC = clang
TARGET	= main
FLAGS	= -Wall -pedantic -std=c99
HEADERS = src/lib.c src/vec_list.c

$(TARGET).out: src/$(TARGET).c
	$(CC) src/$(TARGET).c $(FLAGS) $(HEADERS) -o target/$(TARGET).out

run: $(TARGET).out
	./target/$(TARGET).out $(USER)

test.out: test/tests.c
	$(CC) test/tests.c $(HEADERS) -o target/tests.out

test: test.out
	./target/tests.out

clear:
	rm -f target/*.out
	clear && ls
