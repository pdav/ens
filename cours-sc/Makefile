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

DEPS	= courspda.sty annee.tex logo-uds.pdf licence.tex by-nc.pdf

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
	inc1-intro/motiv-inact.pdf \
	inc1-intro/motiv-part.pdf \
	inc1-intro/motiv-collab.pdf \
	inc1-intro/cpu-freq.pdf \
	inc1-intro/cpu-transist.pdf \
	inc1-intro/cpu-gravure.pdf \
	inc1-intro/motiv-scal.pdf \
	inc1-intro/arbre-exec.pdf \
	inc1-intro/intel-sse.pdf \
	inc1-intro/pipe-486a.pdf \
	inc1-intro/pipe-486b.pdf \
	inc1-intro/pipe-486c.pdf \
	inc1-intro/mem-glob.pdf \
	inc1-intro/mem-dist.pdf \
	inc1-intro/arch-shm.pdf \
	inc1-intro/intel-ht.pdf \
	inc1-intro/intel-mc.pdf \
	inc1-intro/intel-i7.pdf \
	inc1-intro/speedup.pdf \
	inc1-intro/amdahl.pdf \

LSTintro = \

##############################################################################
# Introduction aux API classiques

SRCapi = ch2-api.tex sl2-api.tex

FIGapi = \
	inc2-api/ps-state.pdf \
	inc2-api/ps-def.pdf \
	inc2-api/ps-except.pdf \
	inc2-api/ps-commut.pdf \
	inc2-api/ps-mem.pdf \
	inc2-api/trans-adr.pdf \
	inc2-api/mmu-princ.pdf \
	inc2-api/mmu-ipc.pdf \
	inc2-api/mmu-pdp11a.pdf \
	inc2-api/mmu-pdp11b.pdf \
	inc2-api/mmu-pdp11ex.pdf \
	inc2-api/mmu-i386.pdf \
	inc2-api/mmu-tlb386.pdf \
	inc2-api/msg.pdf \
	inc2-api/shmat.pdf \
	inc2-api/thr-intro.pdf \
	inc2-api/thr-stack.pdf \
	inc2-api/thr-api.pdf \
	inc2-api/thr-sig.pdf \
	inc2-api/bar-intro.pdf \

LSTapi = \
	inc2-api/ipc-msg.c \
	inc2-api/ipc-shm.c \
	inc2-api/thr.c \

##############################################################################
# Exclusion mutuelle

SRCexcl = ch3-excl.tex sl3-excl.tex

FIGexcl = \
	inc3-excl/sect-crit.pdf \
	inc3-excl/int-princ.pdf \
	inc3-excl/int-ack.pdf \
	inc3-excl/int-mask.pdf \
	inc3-excl/sig-mask.pdf \

LSTexcl = \

##############################################################################
# Sémaphores

SRCsem = ch4-sem.tex sl4-sem.tex

FIGsem = \
	inc4-sem/parking.pdf \
	inc4-sem/prodcons-infini.pdf \
	inc4-sem/prodcons-borne.pdf \

LSTsem = \
	inc4-sem/sem-act.c \
	inc4-sem/sem-spin.c \
	inc4-sem/sem-passif.c \
	inc4-sem/ipc-sem.c \
	inc4-sem/prodcons-infini.c \
	inc4-sem/prodcons-borne.c \
	inc4-sem/lect-ecr.c \

##############################################################################
# Interblocage

SRCinterb = ch5-interb.tex sl5-interb.tex

FIGinterb = \
	inc5-interb/gralloc.pdf \
	inc5-interb/gr-0.pdf \
	inc5-interb/gr-1.pdf \
	inc5-interb/gr-sur.pdf \
	inc5-interb/etat-sur.pdf \
	inc5-interb/evit-graphe.pdf \

LSTinterb = \

##############################################################################
# Autres mécanismes de synchronisation de threads

SRCthsync = ch6-thsync.tex sl6-thsync.tex

FIGthsync = \

LSTthsync = \
	inc6-thsync/cond.c \
	inc6-thsync/rw.c \

##############################################################################
# OpenMP

SRCopenmp = ch7-openmp.tex sl7-openmp.tex

FIGopenmp = \
	inc7-openmp/couches.pdf \
	inc7-openmp/fork-join.pdf \
	inc7-openmp/hello.pdf \
	inc7-openmp/reduc.pdf \
	inc7-openmp/parfor.pdf \
	inc7-openmp/parsect.pdf \
	inc7-openmp/parsgl.pdf \

LSTopenmp = \
	inc7-openmp/hello.c \
	inc7-openmp/reduc.c \
	inc7-openmp/parfor.c \
	inc7-openmp/parsect.c \
	inc7-openmp/parsgl.c \
	inc7-openmp/priv.c \
	inc7-openmp/thrpriv.c \
	inc7-openmp/thrcopy.c \
	inc7-openmp/barrier.c \
	inc7-openmp/critical.c \
	inc7-openmp/atomic.c \

##############################################################################
# L'ensemble

SRCall = \
	$(SRCintro) \
	$(SRCapi) \
	$(SRCexcl) \
	$(SRCsem) \
	$(SRCinterb) \
	$(SRCthsync) \
	$(SRCopenmp) \
	tout.tex

FIGall = \
	$(FIGintro) \
	$(FIGapi) \
	$(FIGexcl) \
	$(FIGsem) \
	$(FIGinterb) \
	$(FIGthsync) \
	$(FIGopenmp) \

LSTall = \
	$(LSTintro) \
	$(LSTapi) \
	$(LSTexcl) \
	$(LSTsem) \
	$(LSTinterb) \
	$(LSTthsync) \
	$(LSTopenmp) \

##############################################################################
# Les cibles
##############################################################################

all:	ch1-intro.pdf \
	ch2-api.pdf \
	ch3-excl.pdf \
	ch4-sem.pdf \
	ch5-interb.pdf \
	ch6-thsync.pdf \
	ch7-openmp.pdf

ch1-intro.pdf:	$(DEPS) $(FIGintro) $(LSTintro) $(SRCintro)
ch2-api.pdf:	$(DEPS) $(FIGapi) $(LSTapi) $(SRCapi)
ch3-excl.pdf:	$(DEPS) $(FIGexcl) $(LSTexcl) $(SRCexcl)
ch4-sem.pdf:	$(DEPS) $(FIGsem) $(LSTsem) $(SRCsem)
ch5-interb.pdf:	$(DEPS) $(FIGinterb) $(LSTinterb) $(SRCinterb)
ch6-thsync.pdf:	$(DEPS) $(FIGthsync) $(LSTthsync) $(SRCthsync)
ch7-openmp.pdf:	$(DEPS) $(FIGopenmp) $(LSTopenmp) $(SRCopenmp)

tout.pdf:	$(DEPS) $(FIGall) $(LSTall) $(SRCall)

print: all tout.pdf
	for i in ch?-*.pdf tout.pdf ; do \
	    $(PRINTCMD) -o print-$$i $$i ; \
	done

gencpu:
	@test -d $(CPUDBDIR)  -a -f $(CPUDBDIR)/processor.csv \
		|| (echo "Telecharger la DB depuis http://cpudb.stanford.edu/" dans $(CPUDBDIR) ; exit 1)
	@test "x$$PGUSER" != x -a "x$$PGPASSWORD" != x \
		|| (echo "Il faut initialiser PGUSER et PGPASSWORD" ; exit 1)
	$(GENCPU) $(CPUDBDIR) inc1-intro/cpu-

clean:
	rm -f $(FIGall) *.bak */*.bak *.nav *.out *.aux *.snm *.vrb *.log
	rm -f print-*.pdf ch*.pdf tout.pdf by-nc.pdf
	rm -f inc?-*/a.out
