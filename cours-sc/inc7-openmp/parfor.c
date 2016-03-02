#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

void main () {
    int i, j;     double debut, fin ;

    debut = omp_get_wtime () ;
    for (i = 0; i < 3; i++) {
	#pragma omp parallel default (none) shared (i)
	#pragma omp for
	for (j = 0; j < 8; j++) {
	    printf ("%d/%d thread=%d\n", i, j,
	    			omp_get_thread_num());
	}
    }
    fin = omp_get_wtime () ;
    printf ("temps = %f\n", fin - debut) ;
}
