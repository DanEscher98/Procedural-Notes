CC = clang
TARGET	= main
FLAGS	= -Wall -pedantic -std=c11
HEADERS = src/lib.c src/vec_list.c

$(TARGET).out: src/$(TARGET).c
	$(CC) src/$(TARGET).c $(FLAGS) $(HEADERS) -o target/$(TARGET).out

run: $(TARGET).out
	python3 test/inputs.py | xargs -I % ./target/$(TARGET).out %

test.out: test/tests.c
	$(CC) test/tests.c $(HEADERS) $(FLAGS) -g -o target/tests.out

test: test.out
	valgrind -s --leak-check=full target/tests.out 2> target/mem_analysis.log
	cat target/mem_analysis.log

clear:
	rm -f target/*.out target/*.log
	clear && ls
