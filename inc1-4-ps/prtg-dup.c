fd1 = open ("toto", O_RDONLY) ;
fd2 = open ("toto", O_RDONLY) ;
dup2 (fd1, 5)

read (fd1, ..., 10) ;
read (fd2, ..., 33) ;
read (5, ..., 15) ;
