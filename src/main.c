#include <stdlib.h>
#include "prodconso.h"

void *threadA(void *arg) {
  /*
    gestion de la graine de randr_r à changer !!!
   */
  unsigned int graine = 0;

  for(int i=0; i< 1000; i++) {
    deposer(rand_r(& graine));
  }
  /* */
  return 0;
}

void *threadB(void *arg) {
  for(int i=0; i < 1000; i++) {
     int res = retirer();
     (void)res; /* supprime le warning "unused variable" */
  }
  return 0;
}


int main(int argc, char **argv) {
  /*
    Insérer le code de gestion des threads ici
  */

  return 0;
}
