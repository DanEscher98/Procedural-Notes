TARGET		= main
FLAGS	    = -Wall -Wextra -pedantic
LIBRARYS 	= data_structures.c basic_algorithms.c libraries/safe_io.c

$(TARGET).out : $(TARGET).c $(LIBRARYS)
	clang $(TARGET).c -o $(TARGET).out $(LIBRARYS) $(FLAGS)

run: $(TARGET).out
	./$(TARGET).out

clear:
	rm -f *.out
