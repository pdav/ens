#
# Cibles possibles :
# all: tous les chapitres individuels (ch-lan.pdf, ch-ipv4.pdf, etc.)
# ch-lan.pdf: un chapitre individuel particulier
# ch-ipv4.pdf: idem
# ...
# tout.pdf: un document contenant tous les chapitres (pas fait avec "all")
#

.SUFFIXES:	.pdf .fig .svg .gnu .tex

.fig.pdf:
	fig2dev -L pdf $*.fig > $*.pdf

.svg.pdf:
	inkscape --export-pdf=$*.pdf $*.svg

.gnu.pdf:
	gnuplot < $*.gnu > $*.pdf

.tex.pdf:
	pdflatex $*
	pdflatex $*

# pour la cible print (on peut aussi utiliser la version 6up, ou utiliser
# pdfjam directement avec des paramètres plus sophistiqués)
PRINTCMD = pdfjam-slides3up --quiet --paper a4paper --keepinfo

DEPS	= courspda.sty annee.tex logo-uds.pdf

##############################################################################
# Première partie
##############################################################################

##############################################################################
# Introduction

SRC1intro = ch1-1-intro.tex sl1-1-intro.tex

FIG1intro = \
	inc1-1-intro/spool1.pdf \
	inc1-1-intro/spool2.pdf \
	inc1-1-intro/quantum.pdf \
	inc1-1-intro/noyau.pdf \

IMG1intro = \
	inc1-1-intro/eniac.jpg \
	inc1-1-intro/pdp1.jpg \
	inc1-1-intro/carte-perfo.jpg \
	inc1-1-intro/ibm704.jpg \
	inc1-1-intro/spool-tanenb.png \
	inc1-1-intro/tty.jpg \
	inc1-1-intro/term-adm3a.jpg \

LST1intro = \
	inc1-1-intro/unistd.h \
	inc1-1-intro/errno.h \
	inc1-1-intro/ex-errno1.c \
	inc1-1-intro/perror.c \
	inc1-1-intro/ex-errno2.c \
	inc1-1-intro/ex-ptr-ok.c \
	inc1-1-intro/ex-ptr-bad.c \

##############################################################################
# Fichiers

SRC1file = ch1-2-file.tex sl1-2-file.tex

FIG1file = \
	inc1-2-file/str-fich.pdf \
	inc1-2-file/flags-open.pdf \
	inc1-2-file/bufferisation.pdf \
	inc1-2-file/perm.pdf \
	inc1-2-file/st-mode.pdf \
	inc1-2-file/rep-fmt-v7.pdf \
	inc1-2-file/arbo.pdf \
	inc1-2-file/rep-fmt-ffs.pdf \
	inc1-2-file/lien-1.pdf \
	inc1-2-file/lien-2.pdf \
	inc1-2-file/lien-3.pdf \

IMG1file = \

LST1file = \
	inc1-2-file/lib-open.c \
	inc1-2-file/lib-fopen.c \
	inc1-2-file/ex-dir.c \

##############################################################################
# Périphériques

SRC1dev = ch1-3-dev.tex sl1-3-dev.tex

FIG1dev = \
	inc1-3-dev/arch-old.pdf \
	inc1-3-dev/cdevsw.pdf \
	inc1-3-dev/arch-now.pdf \
	inc1-3-dev/tty.pdf \
	inc1-3-dev/pty.pdf \

IMG1dev = \

LST1dev = \
	inc1-3-dev/lpr.c \
	inc1-3-dev/dsk.c \


##############################################################################
# Processus

SRC1ps = ch1-4-ps.tex sl1-4-ps.tex

FIG1ps = \
	inc1-4-ps/ps-mem.pdf \
	inc1-4-ps/umask.pdf \
	inc1-4-ps/chroot.pdf \
	inc1-4-ps/fork.pdf \
	inc1-4-ps/orphan.pdf \
	inc1-4-ps/etats.pdf \
	inc1-4-ps/exec.pdf \
	inc1-4-ps/env.pdf \
	inc1-4-ps/droits.pdf \
	inc1-4-ps/perm.pdf \
	inc1-4-ps/prtg-dup.pdf \
	inc1-4-ps/prtg-data.pdf \
	inc1-4-ps/prtg-fork.pdf \

IMG1ps = \

LST1ps = \
	inc1-4-ps/getpid.c \
	inc1-4-ps/fork.c \
	inc1-4-ps/ex-fork.c \
	inc1-4-ps/ex-wait.c \
	inc1-4-ps/algo-ps1.c \
	inc1-4-ps/ex-exec.c \
	inc1-4-ps/ex-dup.c \
	inc1-4-ps/ex-dup2.c \
	inc1-4-ps/prtg-dup.c \

##############################################################################
# Temps

SRC1time = ch1-5-time.tex sl1-5-time.tex

FIG1time = \
	inc1-5-time/utimes.pdf \
	inc1-5-time/precision.pdf \

IMG1time = \

LST1time = \
	inc1-5-time/ex-lib.c \


##############################################################################
# Tubes

SRC1tube = ch1-6-pipe.tex sl1-6-pipe.tex

FIG1tube = \
	inc1-6-pipe/principe.pdf \
	inc1-6-pipe/creation-0.pdf \
	inc1-6-pipe/creation-1.pdf \
	inc1-6-pipe/creation-2.pdf \
	inc1-6-pipe/creation-3.pdf \
	inc1-6-pipe/creation-4.pdf \
	inc1-6-pipe/creation-5.pdf \
	inc1-6-pipe/creation-6.pdf \

IMG1tube = \

LST1tube = \
#	inc1-6-pipe/getpid.c \


##############################################################################
# Signaux

SRC1sig = ch1-7-sig.tex sl1-7-sig.tex

FIG1sig = \
	inc1-7-sig/derout.pdf \
	inc1-7-sig/bus.pdf \
	inc1-7-sig/ps-except.pdf \
	inc1-7-sig/sigset.pdf \

IMG1sig = \

LST1sig = \
	inc1-7-sig/compteur.c \
	inc1-7-sig/volatile.c \
	inc1-7-sig/sigaction.c \


##############################################################################
# L'ensemble de la première partie

SRC1all = \
	$(SRC1intro) \
	$(SRC1file) \
	$(SRC1dev) \
	$(SRC1ps) \
	$(SRC1time) \
	$(SRC1tube) \
	$(SRC1sig) \
	tout1.tex

FIG1all = \
	$(FIG1intro) \
	$(FIG1file) \
	$(FIG1dev) \
	$(FIG1ps) \
	$(FIG1time) \
	$(FIG1tube) \
	$(FIG1sig) \

IMG1all = \
	$(IMG1intro) \
	$(IMG1file) \
	$(IMG1dev) \
	$(IMG1ps) \
	$(IMG1time) \
	$(IMG1tube) \
	$(IMG1sig) \

LST1all = \
	$(LST1intro) \
	$(LST1file) \
	$(LST1dev) \
	$(LST1ps) \
	$(LST1time) \
	$(LST1tube) \
	$(LST1sig) \

##############################################################################
# Les cibles
##############################################################################

all:	ch1-1-intro.pdf \
	ch1-2-file.pdf \
	ch1-3-dev.pdf \
	ch1-4-ps.pdf \
	ch1-5-time.pdf \
	ch1-6-pipe.pdf \
	ch1-7-sig.pdf \

ch1-1-intro.pdf: $(DEPS) $(FIG1intro) $(IMG1intro) $(LST1intro) $(SRC1intro)
ch1-2-file.pdf:	$(DEPS) $(FIG1file) $(IMG1file) $(LST1file) $(SRC1file)
ch1-3-dev.pdf:	$(DEPS) $(FIG1dev) $(IMG1dev) $(LST1dev) $(SRC1dev)
ch1-4-ps.pdf:	$(DEPS) $(FIG1ps) $(IMG1ps) $(LST1ps) $(SRC1ps)
ch1-5-time.pdf:	$(DEPS) $(FIG1time) $(IMG1time) $(LST1time) $(SRC1time)
ch1-6-pipe.pdf:	$(DEPS) $(FIG1tube) $(IMG1tube) $(LST1tube) $(SRC1tube)
ch1-7-sig.pdf:	$(DEPS) $(FIG1sig) $(IMG1sig) $(LST1sig) $(SRC1sig)

inc1-2-file/lien-1.pdf: inc1-2-file/lien.fig
	figlayers 40-60       < $< | fig2dev -L pdf > $@
inc1-2-file/lien-2.pdf: inc1-2-file/lien.fig
	figlayers 30-55       < $< | fig2dev -L pdf > $@
inc1-2-file/lien-3.pdf: inc1-2-file/lien.fig
	figlayers 20-29 40-55 < $< | fig2dev -L pdf > $@

inc1-6-pipe/creation-0.pdf: inc1-6-pipe/creation.fig
	figlayers           30 31 40-41 44-45 50-65 < $< | fig2dev -L pdf > $@
inc1-6-pipe/creation-1.pdf: inc1-6-pipe/creation.fig
	figlayers 10 11 40-41 44-45 50-65 99 < $< | fig2dev -L pdf > $@
inc1-6-pipe/creation-2.pdf: inc1-6-pipe/creation.fig
	figlayers 10 12 40-41 44-65 99 < $< | fig2dev -L pdf > $@
inc1-6-pipe/creation-3.pdf: inc1-6-pipe/creation.fig
	figlayers 10 14 35 40 41 43 44-65 99 < $< | fig2dev -L pdf > $@
inc1-6-pipe/creation-4.pdf: inc1-6-pipe/creation.fig
	figlayers 10 15 30 40 43 44-65 99 < $< | fig2dev -L pdf > $@
inc1-6-pipe/creation-5.pdf: inc1-6-pipe/creation.fig
	figlayers 10 16 30 40 45-65 99 < $< | fig2dev -L pdf > $@
inc1-6-pipe/creation-6.pdf: inc1-6-pipe/creation.fig
	figlayers 10 17 36 46-55 99 < $< | fig2dev -L pdf > $@

tout1.pdf:	$(DEPS) $(FIG1all) $(LST1all) $(SRC1all)

print: all tout1.pdf
	for i in ch?-*.pdf tout*.pdf ; do \
	    $(PRINTCMD) -o print-$$i $$i ; \
	done

clean:
	cleantex -a $(SRC1all) tout1.tex
	rm -f $(FIG1all) *.bak */*.bak *.nav *.out *.snm *.vrb
	rm -f print-*.pdf
	rm -f inc?-?-*/a.out
