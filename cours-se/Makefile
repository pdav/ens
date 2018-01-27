#
# Cibles possibles :
# all: tous les chapitres individuels (chx-yyy.pdf)
# chx-yyy.pdf: un chapitre individuel particulier
# ...
# tout.pdf: document contenant tous les chapitres de la deuxième partie
# print: tous les PDF au format "3 pages par page"
#

.SUFFIXES:	.pdf .fig .svg .gnu .tex

.fig.pdf:
	fig2dev -L pdf $*.fig $*.pdf

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

DEPS	= courspda.sty casserole.pdf logo-uds.pdf \
	annee.tex \
	licence.tex by-nc.pdf

##############################################################################
# Introduction

SRCintro = ch1-intro.tex sl1-intro.tex

FIGintro = \
	inc1-intro/acces.pdf \
	inc1-intro/ps-except.pdf \
	inc1-intro/trap-lib.pdf \
	inc1-intro/boot.pdf \

IMGintro = \

LSTintro = \

##############################################################################
# Processus

SRCps = ch2-ps.tex sl2-ps.tex

FIGps = \
	inc2-ps/mem-1.pdf \
	inc2-ps/mem-2.pdf \
	inc2-ps/mem-3.pdf \
	inc2-ps/etats.pdf \
	inc2-ps/ps-commut.pdf \
	inc2-ps/crit.pdf \
	inc2-ps/decay.pdf \

IMGps = \

LSTps = \

##############################################################################
# Système de fichiers

SRCfs = ch3-fs.tex sl3-fs.tex

FIGfs = \
	inc3-fs/pile-0.pdf \
	inc3-fs/pile-1.pdf \
	inc3-fs/pile-2.pdf \
	inc3-fs/pile-3.pdf \
	inc3-fs/pile-4.pdf \
	inc3-fs/pile-5.pdf \
	inc3-fs/disque.pdf \
	inc3-fs/bsdpart.pdf \
	inc3-fs/dospart.pdf \
	inc3-fs/volume.pdf \
	inc3-fs/geometrie.pdf \
	inc3-fs/buffer.pdf \
	inc3-fs/bcache.pdf \
	inc3-fs/inode.pdf \
	inc3-fs/freelist.pdf \
	inc3-fs/mount-0.pdf \
	inc3-fs/mount-1.pdf \
	inc3-fs/mount-2.pdf \
	inc3-fs/vfs.pdf \

IMGfs = \

LSTfs = \

##############################################################################
# Pilotes de périphériques

SRCdev = ch4-dev.tex sl4-dev.tex

FIGdev = \
	inc4-dev/arch-now.pdf \
	inc4-dev/bus.pdf \
	inc4-dev/kbd-ctrl.pdf \
	inc4-dev/cdevsw.pdf \
	inc4-dev/spec.pdf \
	inc4-dev/impr.pdf \

IMGdev = \

LSTdev = \
	inc4-dev/kbd-read.s \
	inc4-dev/kbd-led.s \


##############################################################################
# Mémoire

SRCmem = ch5-mem.tex sl5-mem.tex

FIGmem = \
	inc5-mem/mmu-i386.pdf \
	inc5-mem/mmu-ipc.pdf \
	inc5-mem/mmu-pdp11a.pdf \
	inc5-mem/mmu-pdp11b.pdf \
	inc5-mem/mmu-princ.pdf \
	inc5-mem/mmu-tlb386.pdf \
	inc5-mem/ps-commut.pdf \
	inc5-mem/ps-mem.pdf \
	inc5-mem/trans-adr.pdf \

IMGmem = \
	inc5-mem/hp-ipc.jpg \
	inc5-mem/pdp11.jpg \

LSTmem = \


##############################################################################
# L'ensemble

SRCall = \
	$(SRCintro) \
	$(SRCps) \
	$(SRCfs) \
	$(SRCdev) \
	$(SRCmem) \
	tout.tex

FIGall = \
	$(FIGintro) \
	$(FIGps) \
	$(FIGfs) \
	$(FIGdev) \
	$(FIGmem) \

IMGall = \
	$(IMGintro) \
	$(IMGps) \
	$(IMGfs) \
	$(IMGdev) \
	$(IMGmem) \

LSTall = \
	$(LSTintro) \
	$(LSTps) \
	$(LSTfs) \
	$(LSTdev) \
	$(LSTmem) \

##############################################################################
# Les cibles
##############################################################################

all:	ch1-intro.pdf \
	ch2-ps.pdf \
	ch3-fs.pdf \
	ch4-dev.pdf \
	ch5-mem.pdf \

ch1-intro.pdf: $(DEPS) $(FIGintro) $(IMGintro) $(LSTintro) $(SRCintro)
ch2-ps.pdf:	$(DEPS) $(FIGps) $(IMGps) $(LSTps) $(SRCps)
ch3-fs.pdf:	$(DEPS) $(FIGfs) $(IMGfs) $(LSTfs) $(SRCfs)
ch4-dev.pdf:	$(DEPS) $(FIGdev) $(IMGdev) $(LSTdev) $(SRCdev)
ch5-mem.pdf:	$(DEPS) $(FIGmem) $(IMGmem) $(LSTmem) $(SRCmem)

inc2-ps/mem-1.pdf: inc2-ps/mem.fig
	figlayers 30-39       < $< | fig2dev -L pdf /dev/stdin $@
inc2-ps/mem-2.pdf: inc2-ps/mem.fig
	figlayers 50-69       < $< | fig2dev -L pdf /dev/stdin $@
inc2-ps/mem-3.pdf: inc2-ps/mem.fig
	figlayers 30-99       < $< | fig2dev -L pdf /dev/stdin $@

inc3-fs/pile-0.pdf: inc3-fs/pile.fig
	figlayers       50-99    < $< | fig2dev -L pdf /dev/stdin $@
inc3-fs/pile-1.pdf: inc3-fs/pile.fig
	figlayers 41    50-99    < $< | fig2dev -L pdf /dev/stdin $@
inc3-fs/pile-2.pdf: inc3-fs/pile.fig
	figlayers 42    50-99    < $< | fig2dev -L pdf /dev/stdin $@
inc3-fs/pile-3.pdf: inc3-fs/pile.fig
	figlayers 43    50-99    < $< | fig2dev -L pdf /dev/stdin $@
inc3-fs/pile-4.pdf: inc3-fs/pile.fig
	figlayers 44    50-99    < $< | fig2dev -L pdf /dev/stdin $@
inc3-fs/pile-5.pdf: inc3-fs/pile.fig
	figlayers 45    50-99    < $< | fig2dev -L pdf /dev/stdin $@

inc3-fs/mount-0.pdf: inc3-fs/mount.fig
	figlayers       50-99    < $< | fig2dev -L pdf /dev/stdin $@
inc3-fs/mount-1.pdf: inc3-fs/mount.fig
	figlayers 40    50-99    < $< | fig2dev -L pdf /dev/stdin $@
inc3-fs/mount-2.pdf: inc3-fs/mount.fig
	figlayers 40-49 50-99    < $< | fig2dev -L pdf /dev/stdin $@

tout.pdf:	$(DEPS) $(FIGall) $(LSTall) $(SRCall)

print: all tout.pdf
	for i in ch?-*.pdf tout*.pdf ; do \
	    $(PRINTCMD) -o print-$$i $$i ; \
	done

clean:
	rm -f $(FIGall)
	rm -f *.bak */*.bak *.nav *.out *.snm *.vrb *.log *.toc *.aux
	rm -f print-*.pdf ch*.pdf tout*.pdf by-nc.pdf casserole.pdf
	rm -f inc?-?-*/a.out
