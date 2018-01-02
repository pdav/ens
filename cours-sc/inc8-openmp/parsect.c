#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

void main () {
    int a = rand (), b = rand (), s = 0 ;

    #pragma omp parallel firstprivate (a, b) reduction (+:s)
    #pragma omp sections
    {
	#pragma omp section
	{
	    a = a + a ; s = a ;
	}
	#pragma omp section
	{
	    b = b + b ; s = b ;
	}
    }
    printf ("a=%d, b=%d, s=%d\n", a, b, s) ;
}
