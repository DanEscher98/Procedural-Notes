TARGET		= macros
FLAGS	    = -Wall -Wextra -pedantic
LIBRARYS 	= #data_structures.c basic_algorithms.c

$(TARGET).out : $(TARGET).c $(LIBRARYS)
	clang $(TARGET).c $(LIBRARYS) -o $(TARGET).out $(FLAGS)

asm: $(TARGET).out
	objdump -d $(TARGET).out > $(TARGET).asm

run: $(TARGET).out
	./$(TARGET).out

clear:
	rm -f *.out *.asm *.ll
	clear && ls
