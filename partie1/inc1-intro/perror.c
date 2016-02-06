void perror (const char *msg)
{
    fprintf (stderr, "%s: ", msg) ;
    switch (errno)
    {
	case EPERM :
	    fprintf (stderr, "Operation not permitted\n") ;
	    break ;
	case ENOENT :
	    fprintf (stderr, "No such file or directory") ;
	    break ;
	...
    }
}
