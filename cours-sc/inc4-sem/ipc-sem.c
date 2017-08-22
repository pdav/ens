#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void raler (char *msg)
{
    perror (msg) ;
    exit (1) ;
}

int creer_semaphore (int val)
{
    key_t k ;
    int id ;

    k = ftok ("/etc/passwd", 'S') ;
    if (k == -1)
	raler ("ftok") ;

    id = semget (k, 1, IPC_CREAT | 0666) ;
    if (id == -1)
	raler ("semget") ;

    if (semctl (id, 0, SETVAL, val) == -1)
	raler ("semctl setval") ;

    return id ;
}

int acceder_semaphore (void)
{
    key_t k ;
    int id ;

    k = ftok ("/etc/passwd", 'S') ;
    if (k == -1)
	raler ("ftok") ;

    id = semget (k, 0, 0) ;
    if (id == -1)
	raler ("semget") ;

    return id ;
}

void supprimer_semaphore (int id)
{
    int r ;

    r = semctl (id, 0, IPC_RMID, NULL) ;
    if (r == -1)
	raler ("semctl") ;
}

void P (int id)
{
    struct sembuf s [1] = { {0, -1, 0} } ;

    if (semop (id, s, 1) == -1)
	raler ("semop") ;
}

void V (int id)
{
    struct sembuf s [1] = { {0, 1, 0} } ;

    if (semop (id, s, 1) == -1)
	raler ("semop") ;
}


void usage (char *prog)
{
    fprintf (stderr, "usage: %s c <cpteur>|d|p|v\n", prog) ;
    exit (1) ;
}

int main (int argc, char *argv [])
{
    int id ;
    
    if (argc < 2) usage (argv [0]) ;
    switch (*argv [1]) {
	case 'c' :		/* (c)reer */
	    if (argc < 3) usage (argv [0]) ;
	    (void) creer_semaphore (atoi (argv [2])) ;
	    break ;
	case 'd' :		/* (d)etruire */
	    id = acceder_semaphore () ;
	    supprimer_semaphore (id) ;
	    break ;
	case 'p' :		/* (p) */
	    id = acceder_semaphore () ;
	    P (id) ;
	    break ;
	case 'v' :		/* (v) */
	    id = acceder_semaphore () ;
	    V (id) ;
	    break ;
    }
    exit (0) ;
}
