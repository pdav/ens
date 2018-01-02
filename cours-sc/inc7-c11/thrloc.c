thread_local int x ;               // propre a chaque thread

int une_fonction (int n)
{
    static thread_local int cpt ;  // propre a chaque thread

    cpt = cpt + x + n ;
    return cpt ;
}
