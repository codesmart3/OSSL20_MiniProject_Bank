#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "base.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void print_all_records(Record records[]){
   printf("Printing...\n\n");
   for(int i = 0; i < 1000; i++){
     if(records[i].valid == -1){
       continue;
     }
     printf("Name: %s \n", records[i].name);
     printf("Account Number: %0.0f \n", records[i].accountno);
     printf("Address: %s\n", records[i].address);
     printf("Phone: %s \n", records[i].phoneno);
     printf("-----------\n\n");
   }
}

void print_n_records(Record records[]){
  printf("How many records do you want to print?: ");
  int n = 0;
  scanf("%d", &n);
  printf("Printing...\n\n");
   for(int i = 0; i < n; i++){
     if(records[i].valid == -1){
       continue;
     }
     printf("Name: %s\n", records[i].name);
     printf("Account Number: %0.0f \n", records[i].accountno);
     printf("Address: %s", records[i].address);
     printf("Phone: %s \n", records[i].phoneno);
     printf("-----------\n\n");
   }
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function

//Creates an account with following informations:
//1. Name 2. Phone Number 3. Address 4. Password
void add_a_record(Record records[]){
   // TODO: Modify this function as you need
   printf("adding record...\n");
   double accno = 33330000000000;
   srand(time(NULL));
   int random = rand();
   accno = accno + random;

   char pwconfirm[4];

   int i = 0;
   for(i = 0; i < 1000; i++){
     if(records[i].valid == -1){
       break;
     }
   }

   printf("Please enter your name: ");
   fgets(records[i].name, 100, stdin);
   printf("Please enter your Residental Registration Number(with -): ");

   while(1){
    scanf("%s", records[i].rrn);
    if(strlen(records[i].rrn) < 14 || strlen(records[i].rrn) > 14){
      printf("Wrong fromat of RRN. Please retry: ");
    } else{
      while ((getchar()) != '\n');
      break;
    }
    }

  printf("Please enter your address: ");
  fgets(records[i].address, 100, stdin);
  //while ((getchar()) != '\n');

  printf("Please enter your phone number(with - ): ");
  scanf("%s", records[i].phoneno);
  printf("Please enter 4 digit password: ");
   
    while(1){
      scanf("%s", records[i].password);
      if(strlen(records[i].password) < 4 || strlen(records[i].password) > 4){
        printf("Your password must be 4 digits long: ");
        continue;
      } else
        printf("Please confirm your password: ");
        scanf("%s", pwconfirm);
        if(strcmp(records[i].password, pwconfirm) == 0){
        printf("Password Confirmed!\n");
        break;
      }
      printf("Your Password does not match. Please re-try: ");
  }


   printf("\nCreating Your account");
   for(int i = 0; i < 3; i++){
     printf(".");
     fflush(stdout);
     sleep(1);
   } 
   printf("\nYour account number is: %0.0f\n\n", accno);
   records[i].accountno = accno;
   
   records[i].valid = 1;
}

void save_to_txtfile(Record records[]){
  FILE * fp = fopen("records.txt", "wt");
  if(!fp){
    printf("Error creating a text file");
    return;
  }
  fprintf(fp, "========== Records ==========");

  for(int i = 0; i < 1000; i++){
     if(records[i].valid == -1){
       continue;
     } else{
     fprintf(fp, "Name: %s \n", records[i].name);
     fprintf(fp, "Account Number: %0.0f \n", records[i].accountno);
     fprintf(fp, "Address: %s\n", records[i].address);
     fprintf(fp, "Phone: %s \n", records[i].phoneno);
     fprintf(fp, "-------------------------------\n\n");
     printf("NAME: %s\n", records[i].name);
   }
  }
  printf("Save Success!\n");
}

void delete_record(Record records[]){
  double accno;
  char pw[4];
  char yn;
  int count = 5;

  printf("Please provide your account number: ");
  scanf("%lf", &accno);

  for(int i = 0; i < 1000; i++){
    if(records[i].valid == -1){
      continue;
    }

    if(records[i].accountno == accno){
      
      while(1){
        printf("Please provide 4 digit password: ");
        scanf("%s", pw);
        while ((getchar()) != '\n');
        if(strcmp(records[i].password, pw) == 0){
          while(1){
            printf("Proceed? [y / n]\n");
            scanf("%c", &yn);
            if(yn == 'y'){
              records[i].valid = -1;
              printf("Record Succesfully Deleted.\n\n");
              return;
            } else if(yn == 'n'){
              printf("Deleting process terminated.\n\n");
              return;
            } else{
              printf("Wrong input please try again.\n");
              continue;
            }
            }
        } else{
          printf("Wrong Password. %d tries left.\n", --count);
          if(count <= 0){
            printf("You have given wrong password too many times. Deletion process will now terminate..\n");
            while ((getchar()) != '\n');
            return;
          }
        }
      }
      break;
    }
  }

  printf("No such account.\n\n");

}

void update_record(Record records[]){
  int choice = 0;
  double accno = 0;
  char pw[6];
  char pwconfirm[4];
  int count = 5;
  char uname[100];

  printf("Please enter your account number: ");
  scanf("%lf", &accno);

  for(int i = 0; i < 1000; i++){
    if(records[i].valid == -1)
      continue;
    else if(accno == records[i].accountno){ 
      while(1){
        printf("Please enter password: ");
        scanf("%s", pw);
        while((getchar()) != '\n');
        if(strcmp(pw, records[i].password) == 0){
          break;
        } else{
          printf("Wrong Password. %d tries left.\n", --count);
          if(count <= 0){
            printf("You have given wrong password too many times. Update process will now terminate..\n");
            while ((getchar()) != '\n');
            return;
          }
        }
      }

      printf("\nWhich field do you want to update?\n");
      printf("--------------------\n");
      printf("1. Name\n");
      printf("2. Phone Number\n");
      printf("3. Password\n");
      printf("4. Address\n");
      printf("0. Quit without changing.\n");
      printf("--------------------\n");

      while(1){
        printf("Enter a digit(0-4): ");
        scanf("%d", &choice);
        if(choice < 0 || choice > 4){
          printf("You have given wrong input please try again.\n");
          continue;
        } else
          break;
      }

      switch(choice){
        case 0:
          printf("Quitting without changes..\n\n");
          return;
        case 1: 
          while ((getchar()) != '\n');
          printf("Name: ");
          //fgets(records[i].name, 100, stdin);
          fgets(uname, 100, stdin);
          strcpy(records[i].name, uname);
          printf("Your name has been succesfully updated: %s\n\n", records[i].name);
          printf("Hit Enter to continue...\n");
          return;
        case 2:
          printf("Phone Number(with -): ");
          scanf("%s", records[i].phoneno);
          printf("Your phone number has been succesfully updated: %s\n\n", records[i].phoneno);
          return;
        case 3: 
          printf("New Password: ");
          while(1){
            scanf("%s", records[i].password);
            if(strlen(records[i].password) < 4 || strlen(records[i].password) > 4){
              printf("Your password must be 4 digits long: ");
              continue;
            } else
              printf("Please confirm your password: ");
              scanf("%s", pwconfirm);
              if(strcmp(records[i].password, pwconfirm) == 0){
              printf("Password succesfully updated.\n\n");
              return;
            }
            printf("Your Password does not match. Please re-try: ");
          } // end of while
          return;
        case 4:
          while ((getchar()) != '\n');
          printf("Address: ");
          fgets(records[i].address, 100, stdin);
          //scanf("%s", records[i].address);
          //while ((getchar()) != '\n');
          printf("Your address has been successfully updated: %s\n\n", records[i].address);
          printf("Hit Enter to continue...\n");
          return;
      } // end of switch
      
    } // end of else if
 } // end of for
   printf("Inavlid Account Number.\n\n");
} // end of function

