switch (fork ())
{
    case -1 :
	raler ("fork") ;

    case 0 :		/* fils */
	execl ("/bin/echo", "echo", "a", NULL) ;
	raler ("execl") ;

    default :
	if (wait (&raison) == -1)
	    raler ("wait") ;
	if (WIFEXITED (raison) && WEXITSTATUS (raison) == 0)
	    printf ("ok\n") ;
	else printf ("pas ok\n") ;
}
