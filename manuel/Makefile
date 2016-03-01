#
# Makefile des polys du module Unix, Maîtrise d'Informatique, Paris VI
#
#
# Cibles possibles :
#
# all : génère les .pdf
# clean : efface tout
#
# Historique
#   198?/??/?? : pda : conception
#   1993/01/25 : pda : ajout du format à l'italienne pour le 2 pages par page
#   1997/08/29 : pda : ajout des recommandations pour les projets
#   1997/09/23 : pda : ajout des docs de purify et purecoverage
#   1999/03/28 : pda : ajout de la doc sur les débogueurs
#   2013/08/21 : pda : suppression doc purify
#   2013/08/21 : pda : conversion pdflatex
#


INCLUDES = ue.tex annee.tex by-nc.pdf

all:	manuel.pdf

verif:
	pdflatex manuel

manuel.pdf: manuel.tex $(INCLUDES)
	rm -f manuel.ind
	pdflatex manuel
	makeindex manuel
	pdflatex manuel
	makeindex manuel
	pdflatex manuel

by-nc.pdf: by-nc.svg
	inkscape --export-pdf=$@ $<

clean:
	rm -f *.pdf *.bak
	rm -f *.aux *.idx *.ilg *.ind *.log *.toc *.out
