int fd ;

fd = open ("toto", O_RDONLY) ;
if (fd == -1)
{
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
    exit (1) ;
}
