#include <stdlib.h>
#include "prodconso.h"

void *threadA(void *arg) {
  /*
    Les 4 threads auront respectivement {0,1,2,3} comme graine initiale
   */
  unsigned int graine = ...;

  for(int i=0; i< 1000; i++) {
    deposer( rand_r(& graine) );
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
