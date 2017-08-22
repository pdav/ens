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
#   2015/03/29 : pda : ajout theme mem
#

THEMES = \
	theme-01-c-base.tex \
	theme-02-c-stdio.tex \
	theme-03-c-pointeurs.tex \
	theme-04-c-avance.tex \
	theme-05-ps-fichiers.tex \
	theme-06-ps-proc.tex \
	theme-07-ps-envproc.tex \
	theme-08-ps-tubes.tex \
	theme-09-ps-signaux.tex \
	theme-10-ps-mem.tex \
	theme-11-ps-ipc-sysv.tex msg.pdf \
	theme-12-threads.tex \
	theme-13-sockets.tex

INCLUDES = ue.tex annee.tex $(THEMES) by-nc.pdf

FIGS = msg.pdf

#
# Les règles par défaut
#

.SUFFIXES:	.fig .tex .svg .pdf

.fig.pdf:
	fig2dev -L pdf -l 2 $*.fig $*.pdf

.tex.pdf:
	pdflatex $*
	pdflatex $*
.svg.pdf:
	inkscape --export-pdf=$*.pdf $*.svg

#
# Les cibles "globales"
#

all:	exercices.pdf

#
# Le gros morceau
#

exercices.pdf: exercices.tex $(INCLUDES) $(FIGS)
	pdflatex exercices
	pdflatex exercices			# pour la table des matières

# pour tester rapidement (une seule passe)
verif:	exercices.tex $(FIGS) $(EXAMENS)
	pdflatex exercices

clean:
	rm -f *.pdf *.bak
	rm -f *.aux *.log *.toc *.out
	rm -f $(FIGS)
