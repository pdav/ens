init () {
    ip = ic = 0 ;
    creer_semaphore (Sip, 1) ;
    creer_semaphore (Sic, 1) ;
    creer_semaphore (Secrites, 0) ;
    creer_semaphore (Slibres, N) ;
}
produire (val) {
    P (Slibres)
    P (Sip) ;
    tampon [ip] = val ; ip = (ip + 1) % N ;
    V (Sip) ;
    V (Secrites) ;
}
consommer () {
    P (Secrites) ;
    P (Sic) ;
    val = tampon [ic] ; ic = (ic + 1) % N ;
    V (Sic) ;
    V (Slibres)
    return val ;
}
