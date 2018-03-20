volatile sig_atomic_t condition = 0 ;

void signal_machin (int signum)
{
    (void) signum ;
    condition = 1 ;       // l'événement est arrivé
}

int main (...)
{
    signal (SIGmachin, signal_machin) ;
    ...
    if (! condition)      // si l'événement n'est pas arrivé
	pause ()          // alors attendre l'événement
    ...
}

int main (...)
{
    sigset_t masque, vide ;

    sigemptyset (&vide) ;
    sigemptyset (&masque) ;
    sigaddset (&masque, SIGmachin) ;

    ...
    // section critique : signal SIGmachin masqué
    if (sigprocmask (SIG_BLOCK, &masque, NULL) == -1)
	raler ("masquage") ;
    if (! condition)          // l'événement ne peut pas arriver ici
	sigsuspend (&vide) ;  // section critique levée pendant l'attente
    // quand on est reveillé, on est toujours en section critique
    ...
}
