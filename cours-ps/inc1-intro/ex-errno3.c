void raler (char *msg)
{
    perror (msg) ;
    exit (1) ;
}

...

fd = open ("toto", O_RDONLY) ;
if (fd == -1)
    raler ("open toto") ;

...
