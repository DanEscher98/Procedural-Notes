TARGET	= template
FLAGS	= -f elf64 -g -F dwarf -l $(TARGET).lst


$(TARGET).out : $(TARGET).o
	gcc $(TARGET).o -o $(TARGET).out -no-pie
	# ld $(TARGET).o -o $(TARGET).out

$(TARGET).o : $(TARGET).nasm
	# nasmfmt -ii 4 -ci 30 $(TARGET).nasm
	nasm $(TARGET).nasm -o $(TARGET).o $(FLAGS)

run: $(TARGET).out
	./$(TARGET).out

objdump: $(TARGET).out
	objdump -D $(TARGET).out

clear:
	rm -f *.out *.o *.lst
	clear && exa
