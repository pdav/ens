#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define	MAXSTR	1000

int nthread ;

void *f (void *arg)
{
    int i = * (int *) arg ;
    int *p ;
    
    printf ("Je suis le thread %d (sur %d), tid =%ld\n",
    		i, nthread, pthread_self ()) ;

    p = malloc (sizeof (int)) ;
    *p = i * 2 ;

    pthread_exit (p) ;		/* <=> return p */
}

void raler (int errno, char *msg)
{
    char buf [MAXSTR] ;

    strerror_r (errno, buf, sizeof buf) ;
    fprintf (stderr, "%s: %s\n", msg, buf) ;
    exit (1) ;
}

int main (int argc, char *argv [])
{
    pthread_t *tid ;      int e, i, *ti ;

    nthread = atoi (argv [1]) ;
    tid = malloc (nthread * sizeof (pthread_t)) ;
    ti = malloc (nthread * sizeof (int)) ;
    for (i = 0 ; i < nthread ; i++)
    {
	ti [i] = i ;
	if ((e=pthread_create(&tid[i], NULL, f, &ti[i])) != 0)
	    raler (e, "pthread_create") ;
    }

    for (i = 0 ; i < nthread ; i++)
    {
	void *r ;
	if ((e = pthread_join (tid [i], &r)) != 0)
	    raler (e, "pthread_join") ;
	printf ("Retour du thread %d = %d\n", i, * (int *) r) ;
	free (r) ;
    }
    free (tid) ; free (ti) ;
}
