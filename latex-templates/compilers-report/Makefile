SRC    := $(wildcard *.tex)
PS     := $(SRC:.tex=.ps)
PDF    := $(SRC:.tex=.pdf)

all: $(PDF) $(PS)

%.pdf: %.ps
	ps2pdf $*.ps

%.ps: %.dvi
	dvips -t letter -o $*.ps $*

%.dvi: *.tex
	latex $*

all:
	make -f */Makefile

clean:
	rm -f *.aux *.dvi *~ *.ps *.pdf *.log 

cleanall:
	make clean -f */Makefile
