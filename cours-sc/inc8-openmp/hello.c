#include <unistd.h>
#include <stdio.h>
#include "omp.h"

void main () {
    int i, j, n ;     pid_t p = getpid () ;

    #pragma omp parallel shared (n, p) private (i, j)
    {
	i = omp_get_thread_num () ;    j = i * i ;
	n = omp_get_num_threads () ;
	printf ("hello world %d/%d (pid=%d)\n", i, n, p) ;
    }
    printf ("fini !\n") ;
}
