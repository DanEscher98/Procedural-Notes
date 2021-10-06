FLAGS    = -Wall -Wextra -pedantic
TARGET   = linked_list1
LIBRARYS = matrix_algebra.c safe_io.c

$(TARGET).out : $(TARGET).c $(LIBRARYS)
	clang $(TARGET).c -o $(TARGET).out $(LIBRARYS) $(FLAGS)

run: $(TARGET).out
	./$(TARGET).out

clean:
	rm *.out
