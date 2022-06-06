TARGET	= multitable
TEXFLAGS = --interaction=nonstopmode -shell-escape


pdf: $(TARGET).tex
	pdflatex $(TEXFLAGS) $(TARGET).tex \
		-o $(TARGET).pdf 1> /dev/null

clear:
	rm -rdf *.aux *.log *.pyg _*/
	clear && exa
