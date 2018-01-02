#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

void main () {
    int i ;

    #pragma omp parallel
    {
	#pragma omp single
	printf ("debut\n") ;

	#pragma omp for
	for (i = 0 ; i < 8 ; i++) {
	    printf ("%d: %d\n", omp_get_thread_num (), i) ;
	}

	#pragma omp single
	{
	    printf ("fin\n") ;
	}
    }
}
