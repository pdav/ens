#
# Makefile des polys du module Fondement des Systèmes,
# Licence d'Informatique, L2, ULP
#
#
# Cibles possibles :
#
# all : génère les .pdf
# clean : efface tout
#
# Historique
#   1993/01/25 : pda : conception
#   2013/08/27 : pda : nettoyage pour svnpeda
#

INCLUDES = ue.tex annee.tex mf1.tex mf2.tex mf3.tex mf4.tex
FIGS	= msg.pdf

#
# Les règles par défaut
#

.SUFFIXES:	.fig .tex .pdf

.fig.pdf:
	fig2dev -L pdf -l 2 $*.fig > $*.pdf

.tex.pdf:
	pdflatex $*
	pdflatex $*

#
# Les cibles "globales"
#

all:	exercices.pdf

#
# Le gros morceau
#

exercices.pdf: exercices.tex $(INCLUDES) $(FIGS)

exercices.pdf: exercices.tex
	pdflatex exercices
	pdflatex exercices			# pour la table des matières

# pour tester rapidement (une seule passe)
verif:	exercices.tex $(FIGS) $(EXAMENS)
	pdflatex exercices

clean:
	rm -f *.pdf *.bak
	rm -f *.aux *.log *.toc
	rm -f $(FIGS)
