init () {
    ip = ic = 0 ;
    creer_semaphore (Sip, 1) ;
    creer_semaphore (Sic, 1) ;
    creer_semaphore (Secrites, 0) ;
}
produire (val) {
    P (Sip) ;
    tampon [ip] = val ; ip = ip + 1 ;
    V (Sip) ;
    V (Secrites) ;
}
consommer () {
    P (Secrites) ;
    P (Sic) ;
    val = tampon [ic] ; ic = ic + 1 ;
    V (Sic) ;
    return val ;
}
