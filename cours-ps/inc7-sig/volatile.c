#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t arret = 0 ;

void fct (int sig)
{
    // sig\_atomic\_t $\Rightarrow$ modification en "une" opération
    arret = 1 ;
}

int main (int argc, char *argv [])
{
    int n = 0 ;

    signal (SIGINT, fct) ;

    // volatile $\Rightarrow$ variable relue à chaque iteration
    while (! arret)
	n++ ;

    printf ("%d\n", n) ;
}
