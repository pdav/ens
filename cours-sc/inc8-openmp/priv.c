#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

int v ;

void f (void) {
    v = 5 ;	/* quelle variable v est modifiee ? */
}

void main () {
    #pragma omp parallel private (v)
    {
	f () ;
	printf ("%d\n", v) ;	/* resultat indefini */
    }
}
