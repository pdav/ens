#include <stdio.h>
#include <pthread.h>

pthread_cond_t  c ;
pthread_mutex_t m ;
int var ;

void attendre (void) {
    pthread_mutex_lock (&m) ;
    var = 0 ;
    while (var == 0)
	pthread_cond_wait (&c, &m) ;
    pthread_mutex_unlock (&m) ;
}

void reveiller (void) {
    pthread_mutex_lock (&m) ;
    var = 1 ;	/* section critique si non atomique */
    pthread_mutex_unlock (&m) ;
    pthread_cond_signal (&c) ;
}

void *poireauteur (void *arg) {
    printf ("j'attends\n") ;
    attendre () ;
    printf ("je suis reveille\n") ;
}

void *reveilleur (void *arg) {
    printf ("je reveille\n") ;
    reveiller () ;
}

main () {
    pthread_t tp, tr ;
    pthread_mutex_init (&m, NULL) ;
    pthread_cond_init (&c, NULL) ;
    pthread_create (&tp, NULL, poireauteur, NULL) ;
    sleep (5) ;
    pthread_create (&tr, NULL, reveilleur, NULL) ;
    sleep (5) ;
}
