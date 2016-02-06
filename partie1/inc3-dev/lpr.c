int fd ;

fd = open ("/dev/lpr", O_WRONLY) ;
write (fd, "ligne a imprimer\r\n", 18) ;
close (fd) ;
