TARGET	= syscalls
FLAGS	= -f elf64 -g -F dwarf -l $(TARGET).lst
TEXFLAGS = --interaction=nonstopmode -shell-escape


pdf: $(TARGET).tex
	pdflatex $(TEXFLAGS) $(TARGET).tex \
		-o $(TARGET).pdf 1> /dev/null
	cp $(TARGET).pdf $(HOME)/MyWindows/Working

clear:
	rm -rdf *.aux *.log *.pyg _*/
	clear && exa
