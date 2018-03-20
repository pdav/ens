thread_local int x ;               // propre à chaque thread

int une_fonction (int n)
{
    static thread_local int cpt ;  // propre à chaque thread

    cpt = cpt + x + n ;
    return cpt ;
}
