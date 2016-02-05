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

#
# Extraction (optionnelle) des caracteristiques des processeurs de la
# base des CPU
#
CPUDBDIR = ../cpudb
GENCPU = ./cpudb-extract

##############################################################################
# Introduction

SRCintro = ch1-intro.tex sl1-intro.tex

FIGintro = \
	inc1-intro/spool1.pdf \
	inc1-intro/spool2.pdf \
	inc1-intro/quantum.pdf \
	inc1-intro/noyau.pdf \

IMGintro = \
	inc1-intro/eniac.jpg \
	inc1-intro/pdp1.jpg \
	inc1-intro/carte-perfo.jpg \
	inc1-intro/ibm704.jpg \
	inc1-intro/spool-tanenb.png \
	inc1-intro/tty.jpg \
	inc1-intro/term-adm3a.jpg \

LSTintro = \
	inc1-intro/unistd.h \
	inc1-intro/errno.h \
	inc1-intro/ex-errno1.c \
	inc1-intro/perror.c \
	inc1-intro/ex-errno2.c \
	inc1-intro/ex-ptr-ok.c \
	inc1-intro/ex-ptr-bad.c \

##############################################################################
# Fichiers

SRCfile = ch2-file.tex sl2-file.tex

FIGfile = \
	inc2-file/str-fich.pdf \
	inc2-file/flags-open.pdf \
	inc2-file/bufferisation.pdf \
	inc2-file/perm.pdf \
	inc2-file/st-mode.pdf \
	inc2-file/rep-fmt-v7.pdf \
	inc2-file/arbo.pdf \
	inc2-file/rep-fmt-ffs.pdf \
	inc2-file/lien-1.pdf \
	inc2-file/lien-2.pdf \
	inc2-file/lien-3.pdf \

IMGfile = \

LSTfile = \
	inc2-file/lib-open.c \
	inc2-file/lib-fopen.c \
	inc2-file/ex-dir.c \

##############################################################################
# Périphériques

SRCdev = ch3-dev.tex sl3-dev.tex

FIGdev = \
	inc3-dev/arch-old.pdf \
	inc3-dev/cdevsw.pdf \
	inc3-dev/arch-now.pdf \
	inc3-dev/tty.pdf \
	inc3-dev/pty.pdf \

IMGdev = \

LSTdev = \
	inc3-dev/lpr.c \
	inc3-dev/dsk.c \


##############################################################################
# Processus

SRCps = ch4-ps.tex sl4-ps.tex

FIGps = \
	inc4-ps/segments.pdf \
	inc4-ps/umask.pdf \
	inc4-ps/chroot.pdf \
	inc4-ps/fork.pdf \
	inc4-ps/orphan.pdf \
	inc4-ps/etats.pdf \
	inc4-ps/exec.pdf \
	inc4-ps/env.pdf \
	inc4-ps/droits.pdf \
	inc4-ps/perm.pdf \
	inc4-ps/prtg-dup.pdf \
	inc4-ps/prtg-data.pdf \
	inc4-ps/prtg-fork.pdf \

IMGps = \

LSTps = \
	inc4-ps/getpid.c \
	inc4-ps/fork.c \
	inc4-ps/ex-fork.c \
	inc4-ps/ex-wait.c \
	inc4-ps/algo-ps1.c \
	inc4-ps/ex-exec.c \
	inc4-ps/ex-dup.c \
	inc4-ps/ex-dup2.c \
	inc4-ps/prtg-dup.c \

##############################################################################
# Temps

SRCtime = ch5-time.tex sl5-time.tex

FIGtime = \
	inc5-time/utimes.pdf \
	inc5-time/precision.pdf \

IMGtime = \

LSTtime = \
	inc5-time/ex-lib.c \


##############################################################################
# Tubes

SRCtube = ch6-pipe.tex sl6-pipe.tex

FIGtube = \
	inc6-pipe/principe.pdf \
	inc6-pipe/creation-0.pdf \
	inc6-pipe/creation-1.pdf \
	inc6-pipe/creation-2.pdf \
	inc6-pipe/creation-3.pdf \
	inc6-pipe/creation-4.pdf \
	inc6-pipe/creation-5.pdf \
	inc6-pipe/creation-6.pdf \

IMGtube = \

LSTtube = \
#	inc6-pipe/getpid.c \


##############################################################################
# Signaux

SRCsig = ch7-sig.tex sl7-sig.tex

FIGsig = \
	inc7-sig/derout.pdf \
	inc7-sig/bus.pdf \
	inc7-sig/ps-except.pdf \
	inc7-sig/sigset.pdf \

IMGsig = \

LSTsig = \
	inc7-sig/compteur.c \
	inc7-sig/volatile.c \
	inc7-sig/sigaction.c \


##############################################################################
# L'ensemble

SRCall = \
	$(SRCintro) \
	$(SRCfile) \
	$(SRCdev) \
	$(SRCps) \
	$(SRCtime) \
	$(SRCtube) \
	$(SRCsig) \
	tout.tex

FIGall = \
	$(FIGintro) \
	$(FIGfile) \
	$(FIGdev) \
	$(FIGps) \
	$(FIGtime) \
	$(FIGtube) \
	$(FIGsig) \

IMGall = \
	$(IMGintro) \
	$(IMGfile) \
	$(IMGdev) \
	$(IMGps) \
	$(IMGtime) \
	$(IMGtube) \
	$(IMGsig) \

LSTall = \
	$(LSTintro) \
	$(LSTfile) \
	$(LSTdev) \
	$(LSTps) \
	$(LSTtime) \
	$(LSTtube) \
	$(LSTsig) \

##############################################################################
# Les cibles
##############################################################################

all:	ch1-intro.pdf \
	ch2-file.pdf \
	ch3-dev.pdf \
	ch4-ps.pdf \
	ch5-time.pdf \
	ch6-pipe.pdf \
	ch7-sig.pdf \

ch1-intro.pdf:	$(DEPS) $(FIGintro) $(IMGintro) $(LSTintro) $(SRCintro)
ch2-file.pdf:	$(DEPS) $(FIGfile) $(IMGfile) $(LSTfile) $(SRCfile)
ch3-dev.pdf:	$(DEPS) $(FIGdev) $(IMGdev) $(LSTdev) $(SRCdev)
ch4-ps.pdf:	$(DEPS) $(FIGps) $(IMGps) $(LSTps) $(SRCps)
ch5-time.pdf:	$(DEPS) $(FIGtime) $(IMGtime) $(LSTtime) $(SRCtime)
ch6-pipe.pdf:	$(DEPS) $(FIGtube) $(IMGtube) $(LSTtube) $(SRCtube)
ch7-sig.pdf:	$(DEPS) $(FIGsig) $(IMGsig) $(LSTsig) $(SRCsig)

inc2-file/lien-1.pdf: inc2-file/lien.fig
	figlayers 40-60       < $< | fig2dev -L pdf > $@
inc2-file/lien-2.pdf: inc2-file/lien.fig
	figlayers 30-55       < $< | fig2dev -L pdf > $@
inc2-file/lien-3.pdf: inc2-file/lien.fig
	figlayers 20-29 40-55 < $< | fig2dev -L pdf > $@

inc6-pipe/creation-0.pdf: inc6-pipe/creation.fig
	figlayers           30 31 40-41 44-45 50-65 < $< | fig2dev -L pdf > $@
inc6-pipe/creation-1.pdf: inc6-pipe/creation.fig
	figlayers 10 11 40-41 44-45 50-65 99 < $< | fig2dev -L pdf > $@
inc6-pipe/creation-2.pdf: inc6-pipe/creation.fig
	figlayers 10 12 40-41 44-65 99 < $< | fig2dev -L pdf > $@
inc6-pipe/creation-3.pdf: inc6-pipe/creation.fig
	figlayers 10 14 35 40 41 43 44-65 99 < $< | fig2dev -L pdf > $@
inc6-pipe/creation-4.pdf: inc6-pipe/creation.fig
	figlayers 10 15 30 40 43 44-65 99 < $< | fig2dev -L pdf > $@
inc6-pipe/creation-5.pdf: inc6-pipe/creation.fig
	figlayers 10 16 30 40 45-65 99 < $< | fig2dev -L pdf > $@
inc6-pipe/creation-6.pdf: inc6-pipe/creation.fig
	figlayers 10 17 36 46-55 99 < $< | fig2dev -L pdf > $@

tout.pdf:	$(DEPS) $(FIGall) $(LSTall) $(SRCall)

print: all tout.pdf
	for i in ch?-*.pdf tout.pdf ; do \
	    $(PRINTCMD) -o print-$$i $$i ; \
	done

clean:
	cleantex -a $(SRCall) tout.tex
	rm -f $(FIGall) *.bak */*.bak *.nav *.out *.snm *.vrb
	rm -f print-*.pdf
	rm -f inc?-*/a.out
