verrou v1, v2 ;

P (compteur) {
    spin_lock (v1) ;
    while (compteur <= 0)
	;		// attente active
    spin_lock (v2) ;
    compteur-- ;
    spin_unlock (v2) ;
    spin_unlock (v1) ;
}

V (compteur) {
    spin_lock (v2) ;
    compteur++ ;
    spin_unlock (v2) ;
}
