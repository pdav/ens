extern void g (int x, const char *y) ; // prototype

void f (int a, int b, char *c) // déclaration des paramètres
{
    // déclaration des variables avant les instructions
    struct toto *p ; 

    g (a+b, c) ;               // vérification des arguments
    p = malloc (sizeof *p) ;   // malloc renvoie un void *
}
