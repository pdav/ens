liste = lire_fichiers ("/etc/init/") ;
demarrer_toutes_les_taches (liste) ;
for (;;)
{
    pid = wait (&raison) ;
    ps = chercher_tache (pid, liste) ;
    if (ps != NULL)
	redemarrer_tache (ps) ;
}
