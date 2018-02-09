FILE *fp1, *fp2 ;
int c ;

fp1 = fopen ("toto", "r") ;
if (fp1 == NULL)
    raler ("fopen toto") ;
fp2 = fopen ("titi", "w") ;
if (fp2 == NULL)
    raler ("fopen titi") ;

while ((c = getc (fp1)) != EOF)
    if (putc (c, fp2) == EOF)
	raler ("putc") ;
if (ferror (fp1))
    raler ("getc") ;

if (fclose (fp1) == -1)
    raler ("fclose toto") ;
if (fclose (fp2) == -1)
    raler ("fclose titi") ;
