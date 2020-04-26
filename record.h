#ifndef _RECORD_H_
#define _RECORD_H_

struct Account{
  int accountno[14];
}; 

typedef struct{
   char name[100];
   char rrn[14];
   char phoneno[13];
   double accountno;
   char password[6];
   char address[100];
   int valid;
} Record;



#endif
