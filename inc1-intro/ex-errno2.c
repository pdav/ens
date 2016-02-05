int fd ;

fd = open ("toto", O_RDONLY) ;
if (fd == -1)
{
    perror ("open toto") ;
    exit (1) ;
}
