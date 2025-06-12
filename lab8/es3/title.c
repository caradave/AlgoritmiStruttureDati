#include "title.h"
#include "time.h"

#define MAXC 20

typedef struct Title{
  char name[MAXC];
  struct Title *next;
} Title;



