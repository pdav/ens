DIR *dp ;
struct dirent *d ;

dp = opendir ("/tmp") ;
if (dp == NULL)
    raler ("opendir") ;

while ((d = readdir (dp)) != NULL)
{
    if (strcmp (d->d_name, ".") != 0 &&
	strcmp (d->d_name, "..") != 0)
    {
	printf ("%ld %s\n", d->d_ino, d->d_name) ;
    }
}

if (closedir (dp) == -1)
    raler ("closedir") ;
