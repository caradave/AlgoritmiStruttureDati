#include "date.h"

int compareDate(Date d1, Date d2){
  
  if((d1.yy*10000 + d1.mm*100 + d1.dd) > (d2.yy*10000 + d2.mm*100 + d2.dd))
    return 1;
  else
    return -1;
  return 0;
}

int compareTime(Time t1, Time t2){
  if((t1.hh*10000 + t1.min*100 + t1.sec) > (t2.hh*10000 + t2.min*100 + t2.sec))
    return 1;
  else
    return -1;
  return 0;
}
