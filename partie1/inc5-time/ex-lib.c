time_t heure ;
struct tm *tm ;
char *s1, s2 [MAX] ;
size_t n ;

heure = time (NULL) ;

tm = localtime (&heure) ;

s1 = asctime (tm) ;
printf ("maintenant : %s\n", s1) ;

n = strftime (s2, sizeof s2, "le %d/%m/%Y a %H:%M:%S", tm) ;
if (n == 0)
    printf ("s2 est trop petite\n") ;
else printf ("maintenant : %s\n", s2) ;
