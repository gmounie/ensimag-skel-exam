#include <stdio.h>
#include <stdlib.h>

#define NBTHREADS 4
#define NBLOOPS 1000

int sequence[NBTHREADS][NBLOOPS];
unsigned int graines[NBTHREADS] = {0, 1, 2, 3};

void init_sequence(void) {
  for(int i=0; i < NBLOOPS; i++) {
    for(int j=0; j < NBTHREADS; j++) {
      sequence[j][i] = rand_r( & graines[j] );
    }
  }
}


int main(int argc, char **argv) {
  int indices[NBTHREADS] = {};

  init_sequence();

  int val=0;
  for (int i=0; i < NBLOOPS * NBTHREADS; i++) {
    val = 0;
    scanf("## %d\n", &val);

    for(int j = 0; j < 4; j++) {
      if ( val == sequence[ j ][ indices[j] ] ) {
	indices[j] ++;
	goto suivant;
      }
    }
    fprintf(stderr, "Faute dans les séquences de valeurs:\n\
 lecture correcte des %d flôts jusqu'à ( ", NBTHREADS);

    for(int i=0; i < 4; i++)
      fprintf(stderr, "%d ", indices[i]);
    fprintf(stderr, ")\n");

    fprintf(stderr, "dernière valeur lue: %d\n", val);
    fprintf(stderr, "valeur attendue parmi : ( ");
    for(int i=0; i < 4; i++)
      fprintf(stderr, "%d ", sequence[i] [ indices[i] ]);
    fprintf(stderr, ")\n");

    exit(-1);

  suivant:
    continue;
  }

  return 0;
}
