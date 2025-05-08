#include "persone.h"
#include "date.h"

#define MAXC 50

typedef struct Persone{
  char *cod, *nome, *cognome, *via, *citta;
  int cap;
  Date *dataNascita;
} Persone;

struct Persone *createPersone(struct Persone *p, char *string){
  p = malloc(sizeof(struct Persone));

  p->cod = malloc(MAXC*sizeof(char));
  p->nome = malloc(MAXC*sizeof(char));
  p->cognome = malloc(MAXC*sizeof(char));
  p->via  = malloc(MAXC*sizeof(char));
  p->citta = malloc(MAXC*sizeof(char));

  char *nascita = malloc(10*sizeof(char));

  sscanf(string, "%s %s %s %s %s %s %d\n", p->cod, p->nome, p->cognome, nascita, p->via, p->citta, &p->cap);

  int dd, mm, yy;
  sscanf(nascita, "%d/%d/%d", &dd, &mm, &yy);
  p->dataNascita = createData(p->dataNascita, dd, mm, yy);

  return p;
}

void freePerona(struct Persone *persona){
  freeDate(persona->dataNascita);
  free(persona->cod);
  free(persona->nome);
  free(persona->cognome);
  free(persona->via);
  free(persona->citta);
  free(persona);
}

void printPersona(struct Persone *persona){
  printf("%s %s %s %s %s %s %d\n", persona->cod, persona->nome, persona->cognome, returnData(persona->dataNascita), persona->via, persona->citta, persona->cap);
}

int comparaDataNascita(struct Persone *p1, struct Persone *p2){
  return compareDate(p1->dataNascita, p2->dataNascita);
}

int comparaCodice(struct Persone *p1, char *cod){
  return strcmp(p1->cod, cod);
}
