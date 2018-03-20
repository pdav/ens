#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

int v ;
#pragma omp threadprivate (v)

void f (void) {
    v = 5 ;	// la variable v privée est modifiee
}

void main () {
    #pragma omp parallel
    {
	f () ;
	printf ("%d\n", v) ;	// résultat : 5
    }
}
