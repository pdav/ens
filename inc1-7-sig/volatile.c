#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t arret = 0 ;

void fct (int sig)
{
    /* sig_atomic_t => modification en "une" operation */
    arret = 1 ;
}

int main (int argc, char *argv [])
{
    int n = 0 ;

    signal (SIGINT, fct) ;

    /* volatile => variable relue a chaque iteration */
    while (! arret)
	n++ ;

    printf ("%d\n", n) ;
}
