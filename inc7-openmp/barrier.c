#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

void main () {
    int i, n ;

    #pragma omp parallel default (none) private (i, n)
    {
	i = omp_get_thread_num () ;
	n = omp_get_num_threads () ;
	printf ("Avant : %d/%d\n", i, n) ;

	#pragma omp barrier

	printf ("Apres : %d/%d\n", i, n) ;

    }
}
