#include <stdio.h>
#include "omp.h"

void main () {
    int i, n, s = 1 ;

    #pragma omp parallel shared (n) private (i) \
			 reduction (+:s)
    {
	n = omp_get_num_threads () ;
	i = omp_get_thread_num () ;
	s = i + 1 ;
	printf ("s=%d pour thread numero %d\n", s, i) ;
    }
    printf ("s=%d pour %d threads\n", s, n) ;
}
