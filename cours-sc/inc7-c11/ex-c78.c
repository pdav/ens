f (a, b, c)        /* declaration de la fonction f */
int a, b ;
char *c ;
{
    struct toto *p ;

    g (a+b, c) ;   /* pas de verification des arguments */
    /* malloc renvoie un char * : cast necessaire */
    p = (struct toto *) malloc (sizeof *p) ;
    return a ;     /* renvoie un int par defaut */
}
