pid_t pid ; int raison ;

switch ((pid = fork ())
{
    case -1 :
	raler ("fork") ;
    case 0 :		/* le fils */
	fils () ;
	exit (0) ;
    default :		/* le pere */

	if (wait (&raison) == -1)
	    raler ("wait") ;

	if (WIFEXITED (raison))
	    printf ("exit(%d)\n", WEXITSTATUS (raison)) ;
	else if (WIFSIGNALED (raison))
	    printf ("signal %d\n", WTERMSIG (raison)) ;
	else
	    printf ("autre raison\n") ;
}
