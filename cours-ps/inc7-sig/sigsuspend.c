volatile sig_atomic_t condition = 0 ;

void signal_machin (int signum)
{
    (void) signum ;
    condition = 1 ;       // l'evenement est arrive
}

int main (...)
{
    signal (SIGmachin, signal_machin) ;
    ...
    if (! condition)      // si l'evenement n'est pas arrive
	pause ()          // alors attendre l'evenement
    ...
}

int main (...)
{
    sigset_t masque, vide ;

    sigemptyset (&vide) ;
    sigemptyset (&masque) ;
    sigaddset (&masque, SIGmachin) ;

    ...
    // section critique : signal SIGmachin masque
    if (sigprocmask (SIG_BLOCK, &masque, NULL) == -1)
	raler ("masquage") ;
    if (! condition)          // l'evenement ne peut pas arriver ici
	sigsuspend (&vide) ;  // section critique levee pendant l'attente
    // quand on est reveille, on est toujours en section critique
    ...
}
