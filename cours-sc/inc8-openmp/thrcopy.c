#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

int v ;
#pragma omp threadprivate (v)

void f (void) {
    v = v + v ;
}

void main () {
    v = 2 ;
    #pragma omp parallel copyin (v)
    {
	f () ;
	printf ("%d\n", v) ;	/* 4 dans chaque thread */
    }
}
