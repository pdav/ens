pid_t pid ;
int x = 1 ;

pid = fork () ;
switch (pid)
{
  case -1 : /* erreur */
    raler ("fork") ;

  case 0 :  /* fils */
    x = 5 ;
    break ;

  default : /* pere */
    x = 3 ;
    break ;
}
