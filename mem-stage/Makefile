FIGS =	\
	by-nc.pdf \
	entonnoir.pdf \
	logo-entreprise.pdf \
	logo-uds.pdf \
	logo-ufr.pdf \


memoire.pdf: memoire.tex memoire.bib $(FIGS)
	pdflatex memoire
	bibtex memoire
	pdflatex memoire
	bibtex memoire
	pdflatex memoire


# pour reconstruire le fichier entonnoir.pdf (pas necessaire normalement)
entonnoir.pdf: entonnoir.fig
	fig2dev -L pdf entonnoir.fig entonnoir.pdf

clean:
	rm -f *.aux *.bbl *.blg *.log *.toc *.out
	rm -f memoire.pdf
