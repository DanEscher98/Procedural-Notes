TARGET		= main
FLAGS	    = -Wall -Wextra -pedantic
LIBRARYS 	= data_structures.c basic_algorithms.c

$(TARGET).out : $(TARGET).c $(LIBRARYS)
	clang $(TARGET).c $(LIBRARYS) -o $(TARGET).out $(FLAGS)

run: $(TARGET).out
	./$(TARGET).out

clear:
	clear
	rm -f *.out
