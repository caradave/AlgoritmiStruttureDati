#include "date.h"

int compareDate(Date d1, Date d2){
  if (d1.yy > d2.yy)
    return 1;
  else if (d1.yy < d2.yy)
    return -1;
  else if (d1.mm > d2.mm)
    return 1;
  else if (d1.mm < d2.mm)
    return -1;
  else if (d1.dd > d2.dd)
    return 1;
  else
    return -1;
  return 0;
}
