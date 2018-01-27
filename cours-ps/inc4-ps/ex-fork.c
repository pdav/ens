pid_t pid ;

switch ((pid = fork ())
{
    case -1 :		/* erreur : ne pas oublier */
	raler ("fork") ;

    case 0 :		/* le fils */
	fils () ;		/* isoler le fils */
	exit (0) ;		/* cordon sanitaire */

    default :		/* le pere */
	...
}
