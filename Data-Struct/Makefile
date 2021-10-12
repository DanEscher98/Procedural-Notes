TARGET		= forward_linked_list
FLAGS_CPP	= -Wall -Wextra -pedantic -std=c++17
#FLAGS_C    = -Wall -Wextra -pedantic
#LIBRARYS 	= matrix_algebra.c safe_io.c

$(TARGET).out : $(TARGET).cpp $(LIBRARYS)
	clang $(TARGET).cpp -o $(TARGET).out $(FLAGS)

run: $(TARGET).out
	./$(TARGET).out

clear:
	rm *.out
