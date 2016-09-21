#
# Ce Makefile est destiné à être utilisé par GNU make
#

.SUFFIXES:	.pdf .tex .fig

.tex.pdf:
	pdflatex $*.tex
	pdflatex $*.tex

.fig.pdf:
	fig2dev -Lpdf $*.fig $*.pdf

# Les GNUeries...
TEX	:= conseils.tex
PDF	:= conseils.pdf

all:	$(PDF)

conseils.pdf: conseils.tex indent.pro

clean:
	rm -f *.dvi *.aux *.out *.log *.ps *.eps *.bak ignore.tex *.pdf
