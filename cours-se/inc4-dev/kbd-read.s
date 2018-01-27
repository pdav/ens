// attendre que l'output buffer recoive une donnee du
// clavier

attente:
    IN AL,0x64	  // AL = status register
    TEST AL,0x01  // teste le bit 0 du registre AL
    JZ attente	  // bit 0 = 0 : rien dans l'output buffer

// l'output buffer contient quelque chose : le lire

    IN AL, 0x60   // AL = code de la touche
