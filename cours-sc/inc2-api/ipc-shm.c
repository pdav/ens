#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void raler (char *msg)
{
    perror (msg) ;
    exit (1) ;
}

int creer_segment (void)
{
    key_t k ;
    int id ;

    k = ftok ("/etc/passwd", 'M') ;
    if (k == -1)
	raler ("ftok") ;

    id = shmget (k, 4096, IPC_CREAT | 0666) ;
    if (id == -1)
	raler ("shmget") ;

    return id ;
}

int acceder_segment (void)
{
    key_t k ;
    int id ;

    k = ftok ("/etc/passwd", 'M') ;
    if (k == -1)
	raler ("ftok") ;

    id = shmget (k, 0, 0) ;
    if (id == -1)
	raler ("shmget") ;

    return id ;
}

void supprimer_segment (int id)
{
    int r ;

    r = shmctl (id, IPC_RMID, NULL) ;
    if (r == -1)
	raler ("shmctl") ;
}

void ecrire_valeurs (int id, int v1, int v2)
{
    int *adr ;

    adr = shmat (id, NULL, 0) ;
    if (adr == NULL)
	raler ("shmat") ;

    adr [0] = v1 ;
    adr [1] = v2 ;

    if (shmdt (adr) == -1)
	raler ("shmdt") ;
}

void lire_valeurs (int id, int *v1, int *v2)
{
    int *adr ;

    adr = shmat (id, NULL, 0) ;
    if (adr == NULL)
	raler ("shmat") ;

    *v1 = adr [0] ;
    *v2 = adr [1] ;

    if (shmdt (adr) == -1)
	raler ("shmdt") ;
}


void usage (char *prog)
{
    fprintf (stderr, "usage: %s c|d|e val|l\n", prog) ;
    exit (1) ;
}

int main (int argc, char *argv [])
{
    int id, v1, v2 ;
    
    if (argc < 2) usage (argv [0]) ;
    switch (*argv [1]) {
	case 'c' :		/* (c)reer */
	    (void) creer_segment () ;
	    break ;
	case 'd' :		/* (d)etruire */
	    id = acceder_segment () ;
	    supprimer_segment (id) ;
	    break ;
	case 'e' :		/* (e)crire */
	    id = acceder_segment () ;
	    if (argc < 4) usage (argv [0]) ;
	    ecrire_valeurs (id, atoi (argv [2]), atoi (argv [3])) ;
	    break ;
	case 'l' :		/* (l)ire */
	    id = acceder_segment () ;
	    lire_valeurs (id, &v1, &v2) ;
	    printf ("v1 = %d, v2 = %d\n", v1, v2) ;
	    break ;
    }
    exit (0) ;
}
