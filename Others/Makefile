FILE		= main
C99FLAGS	= -Wall -Wextra -pedantic -std=c99
CPPFLAGS	= -Wall -Wextra -pedantic -std=c++17 -lstdc++

$(FILE).out : $(FILE).c
	clang $(FILE).c -o $(FILE).out $(C99FLAGS)

run : $(FILE).out
	./$(FILE).out

clear :
	rm *.out
	clear && exa
