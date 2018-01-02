extern void g (int x, const char *y) ; /* prototype */

void f (int a, int b, char *c) /* declaration des parametres */
{
    /* declaration des variables avant les instructions */
    struct toto *p ; 

    g (a+b, c) ;               /* verification des arguments */
    p = malloc (sizeof *p) ;   /* malloc renvoie un void * */
}
