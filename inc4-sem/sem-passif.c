P (S) {
    S.compteur-- ;
    if (S.compteur < 0) {
	ajouter_fifo (S.liste, ps_courant) ;
	attendre () ;
    }
}

V (S) {
    S.compteur++ ;
    if (S.compteur <= 0) {
	ps = extraire_fifo (S.liste) ;
	reveiller (ps) ;
    }
}
