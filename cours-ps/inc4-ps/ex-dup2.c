fd = open ("toto", O_WRONLY | O_CREAT | O_TRUNC, 0666) ;
if (fd == -1)
    raler ("open") ;
if (dup2 (fd, 1) == -1)
    raler ("dup2") ;
if (close (fd) == -1)
    raler ("close") ;
execv (path, tabargv) ;
raler ("execv") ;
