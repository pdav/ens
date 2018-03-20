#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

void raler (char *msg)
{
    perror (msg) ;
    exit (1) ;
}

int creer_file (void)
{
    key_t k ;
    int id ;

    k = ftok ("/etc/passwd", 'F') ;
    if (k == -1)
	raler ("ftok") ;

    id = msgget (k, IPC_CREAT | 0666) ;
    if (id == -1)
	raler ("msgget") ;

    return id ;
}

int acceder_file (void)
{
    key_t k ;
    int id ;

    k = ftok ("/etc/passwd", 'F') ;
    if (k == -1)
	raler ("ftok") ;

    id = msgget (k, 0) ;
    if (id == -1)
	raler ("msgget") ;

    return id ;
}

void supprimer_file (int id)
{
    int r ;

    r = msgctl (id, IPC_RMID, NULL) ;
    if (r == -1)
	raler ("msgctl") ;
}

struct message
{
    long mtype ;
    int val ;
} ;

void ecrire_valeur (int id, int val)
{
    struct message m ;   int r ;

    m.mtype = 25 ;
    m.val = val ;
    r = msgsnd (id, &m, sizeof m - sizeof m.mtype, 0) ;
    if (r == -1)
	raler ("msgsnd") ;
}

int lire_valeur (int id)
{
    struct message m ;   int r, val ;

    r = msgrcv (id, &m, sizeof m - sizeof m.mtype, 25, 0) ;
    if (r == -1)
	raler ("msgrcv") ;
    return m.val ;
}


void usage (char *prog)
{
    fprintf (stderr, "usage: %s c|d|e val|l\n", prog) ;
    exit (1) ;
}

int main (int argc, char *argv [])
{
    int id, val ;
    
    if (argc < 2) usage (argv [0]) ;
    switch (*argv [1]) {
	case 'c' :		// (c)reer
	    (void) creer_file () ;
	    break ;
	case 'd' :		// (d)etruire
	    id = acceder_file () ;
	    supprimer_file (id) ;
	    break ;
	case 'e' :		// (e)crire
	    id = acceder_file () ;
	    if (argc < 3) usage (argv [0]) ;
	    ecrire_valeur (id, atoi (argv [2])) ;
	    break ;
	case 'l' :		// (l)ire
	    id = acceder_file () ;
	    val = lire_valeur (id) ;
	    printf ("val = %d\n", val) ;
	    break ;
    }
    exit (0) ;
}
