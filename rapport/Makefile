FIGS = entonnoir.pdf \
	logo-entreprise.pdf \
	logo-uds.pdf \
	logo-ufr.pdf \

rapport.pdf: rapport.tex rapport.bib $(FIGS)
	pdflatex rapport
	bibtex rapport
	pdflatex rapport
	bibtex rapport
	pdflatex rapport

# pour reconstruire le fichier entonnoir.pdf (pas necessaire normalement)
entonnoir.pdf: entoinnoir.fig
	fig2dev -L pdf entonnoir.fig entonnoir.pdf

clean:
	rm -f *.aux *.bbl *.blg *.log *.toc
	rm -f rapport.pdf
