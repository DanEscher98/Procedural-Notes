TARGET		= hash_main
FLAGS	    = -Wall -Wextra -pedantic
LIBRARYS 	= hash_structures.c libraries/safe_io.c

$(TARGET).out : $(TARGET).c $(LIBRARYS)
	clang $(TARGET).c $(LIBRARYS) -o $(TARGET).out $(FLAGS)

run: $(TARGET).out
	./$(TARGET).out

clear:
	rm -f *.out
	clear && exa
