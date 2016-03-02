uint8_t bloc [512] ;
int fd ;

fd = open ("/dev/disk2", O_RDONLY) ;
read (fd, bloc, sizeof bloc) ;
close (fd) ;
