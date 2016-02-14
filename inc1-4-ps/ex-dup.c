fd = open ("toto", O_WRONLY | O_CREAT | O_TRUNC, 0666) ;
if (fd == -1)
    raler ("open") ;
close (1) ;
if (dup (fd) == -1)
    raler ("dup") ;
if (close (fd))
    raler ("close") ;
execv (path, tabargv) ;
raler ("execv") ;
