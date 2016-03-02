#include <stdio.h>
#include <pthread.h>

pthread_rwlock_t verrou ;

int lecteur (void) {
    pthread_rwlock_rdlock (&verrou) ;
    int v = /* lecture */ ;
    pthread_rwlock_unlock (&verrou) ;
    return v ;
}

void ecrivain (int v) {
    pthread_rwlock_wrlock (&verrou) ;
    /* ecriture */ = v ;
    pthread_rwlock_unlock (&verrou) ;
}
