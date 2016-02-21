// envoyer la commande 0xed au control register
// pour allumer les LED (qui doivent etre specifiees
// via l'input buffer)

    OUT 0x60, 0xed

// attendre que l'input buffer soit vide (donnee
// d'une precedente commande)

boucle:
    IN AL,0x64	    // AL = status register
    TEST AL,0x02    // teste le bit 1 du registre AL
    JNZ boucle	    // bit 1 != 0 : input buffer non vide

// specifier les LED a allumer via les bits dans l'input buffer
// 0x01 : ScrollLock, 0x02 : NumLock, 0x04 : CapsLock

    OUT 0x60, 0x06  // ecrire dans l'input buffer
