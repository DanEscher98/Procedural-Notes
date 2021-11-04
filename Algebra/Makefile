TARGET		= main
FLAGS	    = -Wall -Wextra -pedantic -std=c18
LIBRARYS 	= vectors_matrix.h

$(TARGET).out : $(TARGET).c $(LIBRARYS)
	clang $(TARGET).c $(LIBRARYS) -o $(TARGET).out $(FLAGS)

run: $(TARGET).out
	./$(TARGET).out

clear:
	rm -f *.out
	clear && exa
