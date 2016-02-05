void fct (int sig)
{
    ...
}

int main (...)
{
    struct sigaction s ;

    s.sa_handler = fct ;
    s.sa_flags = 0 ;			/* souvent */
    sigemptyset (&s.sa_mask) ;		/* toujours */
    sigaddset (&s.sa_mask, SIGQUIT) ;   /* par ex. */

    sigaction (SIGINT, &s, NULL) ;
    ...
}
