int fd1, fd2 ;
char c ; ssize_t n ;

fd1 = open ("toto", O_RDONLY) ;
if (fd1 == -1)
    raler ("open toto") ;
fd2 = open ("titi", O_WRONLY | O_CREAT | O_TRUNC, 0666) ;
if (fd2 == -1)
    raler ("open titi") ;

while ((n = read (fd1, &c, 1)) > 0)
    if (write (fd2, &c, 1) == -1)
	raler ("write") ;
if (n == -1)
    raler ("read") ;

if (close (fd1) == -1)
    raler ("close toto") ;
if (close (fd2) == -1)
    raler ("close titi") ;
