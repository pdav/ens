void incrementer (void)
{
    sigset_t masque, vieux ;

    // masquer SIGINT
    sigemptyset (&masque) ;
    sigaddset (&masque, SIGINT) ;
    if (sigprocmask (SIG_BLOCK, &masque, &vieux) == -1)
	raler ("masquage") ;

    // début de section critique
    if (c.grand == UINT32_MAX)
    {
	c.grand = 0 ;
	c.tresgrand++ ;
    }
    else c.grand++ ;
    // fin de section critique

    // démasquer SIGINT
    if (sigprocmask (SIG_SETMASK, &vieux, NULL) == -1)
	raler ("demasquage") ;
}
