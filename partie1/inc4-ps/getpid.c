pid_t pid, ppid ;
uid_t uid ;
gid_t gid ;

pid = getpid () ;
printf ("je suis le processus %d\n", pid) ;
ppid = getppid () ;
printf ("mon pere est %d\n", ppid) ;
uid = getuid () ;
printf ("mon proprio est %d\n", uid) ;
gid = getgid () ;
printf ("et mon groupe est %d\n", gid) ;
