#include <stdio.h>
#include <string.h>
#include "extras.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record records[], int num){
   // TODO: Modify this function as you need
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
   printf("defragment(): %d\n\n", num);
   return 0;   // TODO: return 1 if defragment succeed; return 0 otherwise 
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(Record records[]){
   // TODO: Modify this function as you need
   printf("display_stats(): this function needs to be implemented\n\n"); // TODO: Remove this line
}


// TODO: Add more functions to fulfill the optional requirements
