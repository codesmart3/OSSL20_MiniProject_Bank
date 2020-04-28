#include <stdio.h>
#include <string.h>
#include "extras.h"

int defragment(Record records[], int num){
   int empty = 0;
   int num_records = num;
   int j = 0;

   for(int i = num; i < 1000; i++){
     if(records[i].valid != -1){
       j++;
       continue;
     } else{
       empty = i;
       while(1){
         empty++;
         if(records[empty].valid != -1){
           strcpy(records[i].name, records[empty].name);
           strcpy(records[i].password, records[empty].password);
           strcpy(records[i].address, records[empty].address);
           strcpy(records[i].rrn, records[empty].rrn);
           strcpy(records[i].phoneno, records[empty].phoneno);
           records[i].accountno = records[empty].accountno;
           records[i].valid = 1;
           records[empty].valid = -1;
           break;
         }
         if(empty + i > 999){
           break;
         }
       }
     }
   }
   printf("Defragmentation Complete!\n\n");
   return 1;   
}


