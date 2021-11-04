TARGET		= main
FLAGS	    = -Wall -Wextra -pedantic -std=c99
LIBRARYS 	= 

$(TARGET).out : $(TARGET).c $(LIBRARYS)
	clang $(TARGET).c $(LIBRARYS) -o $(TARGET).out $(FLAGS)

run: $(TARGET).out
	./$(TARGET).out

clear:
	rm -f *.out
	clear && exa
