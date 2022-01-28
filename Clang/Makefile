CC = clang
TARGET	= main
FLAGS	= -Wall -pedantic -std=c99
HEADERS = src/lib.c

$(TARGET).out: src/$(TARGET).c
	$(CC) src/$(TARGET).c $(FLAGS) $(HEADERS) -o target/$(TARGET).out

run: $(TARGET).out
	./target/$(TARGET).out $(USER)	

test.out: test/tests.c
	$(CC) test/tests.c $(HEADERS) -g -o target/tests.out

test: test.out
	valgrind -s --leak-check=full target/tests.out 2> target/mem_analysis.log
	cat target/mem_analysis.log | cut --complement -d  -f1 | uniq

clear:
	rm -f target/*.out
	clear && ls
